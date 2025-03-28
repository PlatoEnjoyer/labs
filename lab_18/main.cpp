#include <SFML/Graphics.hpp>

float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::CircleShape shape(30.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(300.f, 400.f);

    sf::RectangleShape rect(sf::Vector2(70.f, 125.f));
    rect.setFillColor(sf::Color::Red);
    rect.move(100.f, 100.f);
    rect.setRotation(45.f);
    rect.setOrigin(35.f, 65.f);

    sf::Vector2 pointA(250.f, 450.f);
    sf::Vector2 pointB(700.f, 300.f);
    sf::Vector2f direction = pointB - pointA;
    float length = sqrt(direction.x * direction.x - direction.y * direction.y);
    direction /= length;

    sf::Clock clock;
    float rotationSpeed = 45.f;
    float speed = 200.f;
    bool movingToB = true;

    sf::Vertex line[] = {
        sf::Vertex(pointA, sf::Color::White),
        sf::Vertex(pointB, sf::Color::White)
    };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        rect.rotate(rotationSpeed * 3 * deltaTime);

        sf::Vector2f currentPos = shape.getPosition();

        if (movingToB) {
            currentPos += speed * deltaTime * direction;
            shape.setPosition(currentPos);
            if (distance(currentPos, pointA) >= length) { 
                currentPos = pointB;
                movingToB = false;
            }
        } else {
            currentPos -= speed * deltaTime * direction;
            shape.setPosition(currentPos);
            if (distance(currentPos, pointB) >= length) { 
                currentPos = pointA;
                movingToB = true;
            }
        }
        window.clear();
        window.draw(shape);
        window.draw(rect);
        window.draw(line, 2, sf::Lines);
        window.display();
    }

    return 0;
}