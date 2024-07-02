
#include <SFML/Graphics.hpp>
#include "include/Grid.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ventana nueva pa", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    
    // position, totalCells and cellsSize
    Grid grid(
              sf::Vector2f(50, 50), 
              sf::Vector2i(150, 80),
              sf::Vector2i(8, 8), 2
             );

    grid.Load();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        window.clear(sf::Color::Black);
        grid.Draw(window);
        window.display();
    }
    return 0;
}