#include <SFML/Graphics.hpp>


const float G = 500.0f; 

float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

struct Planet {
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vector2f position;
    float mass;
    float radius;

    Planet(float r, float m, sf::Color color, sf::Vector2f pos) {
        shape.setRadius(r);
        shape.setOrigin(r, r);
        shape.setPosition(pos);
        shape.setFillColor(color);
        shape.setPointCount(64);
        mass = m;
        radius = r;
        velocity = sf::Vector2f(0, 0);
        position = pos;
    }
};

Planet* draggedPlanet = nullptr;

sf::Vector2f calculateForce(const Planet& a, const Planet& b) {
    sf::Vector2f delta = b.shape.getPosition() - a.shape.getPosition();
    float distanceSq = delta.x * delta.x + delta.y * delta.y;
    float distance = sqrt(distanceSq);

    if (distance < a.radius + b.radius) distance = a.radius + b.radius;
    
    float forceMagnitude = G * (a.mass * b.mass) / distanceSq;
    sf::Vector2f force = (delta / distance) * forceMagnitude; 
    
    return force;
}

void updatePlanets(std::vector<Planet>& planets, float deltaTime) {
    for (size_t i = 0; i < planets.size(); ++i) {
        sf::Vector2f totalForce(0, 0);
        
        for (size_t j = 0; j < planets.size(); ++j) {
            if (i == j) continue;
            totalForce += calculateForce(planets[i], planets[j]);
        }
        
        sf::Vector2f acceleration = totalForce / planets[i].mass;
        
        planets[i].velocity += acceleration * deltaTime;
        planets[i].shape.move(planets[i].velocity * deltaTime);
    }
}

int main() {
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Планетарная система");
    window.setFramerateLimit(60);
    std::vector<sf::VertexArray> trails;

    std::vector<Planet> planets;
    planets.emplace_back(30.0f, 5000.0f, sf::Color(255, 200, 0), sf::Vector2f(400, 400));
    
    planets.emplace_back(15.0f, 75.0f, sf::Color::Blue, sf::Vector2f(400, 200));
    planets.back().velocity = sf::Vector2f(120.0f, 45.0f);
    
    planets.emplace_back(10.0f, 50.0f, sf::Color::Red, sf::Vector2f(300, 250));
    planets.back().velocity = sf::Vector2f(90.0f, 30.0f);

    planets.emplace_back(5.0f, 25.0f, sf::Color::White, sf::Vector2f(600, 400));
    planets.back().velocity = sf::Vector2f(45.0f, 45.0f);
    
    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(
                        sf::Vector2i(event.mouseButton.x, event.mouseButton.y)
                    );

                    for (auto& planet : planets) {
                        float distance = std::hypot(
                            mousePos.x - planet.shape.getPosition().x,
                            mousePos.y - planet.shape.getPosition().y
                        );
                        if (distance <= planet.shape.getRadius()) {
                            draggedPlanet = &planet;
                            break;
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    draggedPlanet = nullptr;
                }
            }

            if (event.type == sf::Event::MouseMoved && draggedPlanet) {
                sf::Vector2f mousePos = window.mapPixelToCoords(
                    sf::Vector2i(event.mouseMove.x, event.mouseMove.y)
                );
                draggedPlanet->shape.setPosition(mousePos);
                draggedPlanet->velocity = sf::Vector2f(45.0f, 45.0f);
            }

            if (!draggedPlanet) {
                updatePlanets(planets, clock.restart().asSeconds());
            }
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