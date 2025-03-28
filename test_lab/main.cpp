#include <SFML/Graphics.hpp>


const float G = 1000.0f; // Искусственная "гравитационная постоянная"

float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

struct Planet {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float mass;
    float radius;

    Planet(float r, float m, sf::Color color, sf::Vector2f pos) {
        shape.setRadius(r);
        shape.setOrigin(r, r);
        shape.setPosition(pos);
        shape.setFillColor(color);
        mass = m;
        radius = r;
        velocity = sf::Vector2f(0, 0);
    }
};

sf::Vector2f calculateForce(const Planet& a, const Planet& b) {
    sf::Vector2f delta = b.shape.getPosition() - a.shape.getPosition();
    float distanceSq = delta.x * delta.x + delta.y * delta.y;
    float distance = sqrt(distanceSq);
    
    // Избегаем деления на 0 и "слипания" планет
    if (distance < a.radius + b.radius) distance = a.radius + b.radius;
    
    float forceMagnitude = G * (a.mass * b.mass) / distanceSq;
    sf::Vector2f force = (delta / distance) * forceMagnitude; // Нормализуем и умножаем на силу
    
    return force;
}

void updatePlanets(std::vector<Planet>& planets, float deltaTime) {
    for (size_t i = 0; i < planets.size(); ++i) {
        sf::Vector2f totalForce(0, 0);
        
        // Суммируем силы от всех других планет
        for (size_t j = 0; j < planets.size(); ++j) {
            if (i == j) continue;
            totalForce += calculateForce(planets[i], planets[j]);
        }
        
        // Ускорение (F = ma → a = F/m)
        sf::Vector2f acceleration = totalForce / planets[i].mass;
        
        // Обновляем скорость и позицию
        planets[i].velocity += acceleration * deltaTime;
        planets[i].shape.move(planets[i].velocity * deltaTime);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Планетарная система");
    window.setFramerateLimit(60);
    
    std::vector<Planet> planets;
    
    // Солнце (неподвижное, с большой массой)
    planets.emplace_back(30.0f, 5000.0f, sf::Color::Yellow, sf::Vector2f(400, 400));
    
    // Земля (начальная скорость для орбиты)
    planets.emplace_back(15.0f, 50.0f, sf::Color::Blue, sf::Vector2f(400, 200));
    planets.back().velocity = sf::Vector2f(120.0f, 0); // Движение по орбите
    
    // Марс
    planets.emplace_back(10.0f, 30.0f, sf::Color::Red, sf::Vector2f(400, 300));
    planets.back().velocity = sf::Vector2f(90.0f, 0);
    
    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        float deltaTime = clock.restart().asSeconds();
        updatePlanets(planets, deltaTime);
        
        window.clear(sf::Color::Black);
        for (const auto& planet : planets) {
            window.draw(planet.shape);
        }
        window.display();
    }
    
    return 0;
}