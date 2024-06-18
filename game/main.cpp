#include "Skeleton.h"
#include "Player.h"
#include "FrameRate.h"


int main()
{
    // ---------------------- Creating window ---------------------- 
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Ventana nueva pa", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    
    // ---------------------- Skeleton ---------------------- 
    Skeleton skeleton;
    skeleton.Load();
    // ---------------------- Player ---------------------- 
    Player player;
    player.Load();
      
    // ---------------------- Delta time ---------------------- 
    FrameRate frameRate;
    frameRate.Load();
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

        frameRate.Update();
        double deltaTime = frameRate.GetDeltaTime();
        player.Update(skeleton, deltaTime);

        window.clear(sf::Color::Black);
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);
        window.display();
    }

    return 0;
}