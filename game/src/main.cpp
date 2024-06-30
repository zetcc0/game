#include "include/Skeleton.h"
#include "include/Player.h"
#include "include/FrameRate.h"
#include "include/Map.h"
#include "include/MapLoader.h"
#include "include/MapData.h"


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
    
    // ---------------------- Map ---------------------- 
    Map map;
    map.Load();

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

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        float deltaTime = (float)frameRate.GetDeltaTime();
        
        frameRate.Update();
        player.Update(skeleton, window, mousePosition, deltaTime);
        skeleton.Update();
        
        window.clear(sf::Color::Black);

        map.Draw(window);
        skeleton.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);
        
        window.display();
    }

    return 0;
}