#include <SFML/Graphics.hpp>

int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana nueva pa", sf::Style::Default, settings);
    sf::CircleShape shape(100.f);
    sf::Vector2f vector(100, 100);
    shape.setPosition(vector);
    shape.setFillColor(sf::Color::Blue);
    shape.setOutlineThickness(10);
    int movement = 10;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::Key::Up and event.type == sf::Event::KeyPressed)
                shape.setRadius(shape.getRadius() + 1);
            if (event.key.code == sf::Keyboard::Key::Down and event.type == sf::Event::KeyPressed)
                shape.setRadius(shape.getRadius() - 1);

            if (event.key.code == sf::Keyboard::Key::S and event.type == sf::Event::KeyPressed)
                vector.y += movement;
                shape.setPosition(vector);
            if (event.key.code == sf::Keyboard::Key::W and event.type == sf::Event::KeyPressed)
                vector.y -= movement;
                shape.setPosition(vector);
            if (event.key.code == sf::Keyboard::Key::A and event.type == sf::Event::KeyPressed)
                vector.x -= movement;
                shape.setPosition(vector);
            if (event.key.code == sf::Keyboard::Key::D and event.type == sf::Event::KeyPressed)
                vector.x += movement;
                shape.setPosition(vector);
        }
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    return 0;
}