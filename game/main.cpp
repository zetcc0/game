#include "Skeleton.h"
#include "Player.h"



int main()
{
    // ---------------------- Creating window ---------------------- 
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana nueva pa", sf::Style::Default, settings);
    //  ---------------------- End Creating window ---------------------- 

    // ---------------------- Skeleton ---------------------- 
    Skeleton skeleton;
    skeleton.Initialize();
    skeleton.Load();
    // ---------------------- Player ---------------------- 
    Player player;
    player.Initialize();
    player.Load();

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
        
        player.Update(skeleton);

        window.clear(sf::Color::Black);
        skeleton.Draw(window);
        player.Draw(window);
        window.display();
    }

    return 0;
}