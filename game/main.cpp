#include <SFML/Graphics.hpp>

int main()
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana nueva pa", sf::Style::Default, settings);
    
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    sf::Vector2f vector(100, 100);
    int movement = 1;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) 
    {
        playerSprite.setTexture(playerTexture);
    }
    playerSprite.setPosition(vector);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            /*if (event.key.code == sf::Keyboard::Key::S && event.type == sf::Event::KeyPressed)
            {
                vector.y += movement;
                playerSprite.setPosition(vector);
                playerSprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
            }
            if (event.key.code == sf::Keyboard::Key::W && event.type == sf::Event::KeyPressed)
            {
                vector.y -= movement;
                playerSprite.setPosition(vector);
                playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
            }
            if (event.key.code == sf::Keyboard::Key::A && event.type == sf::Event::KeyPressed)
            {
                vector.x -= movement;
                playerSprite.setPosition(vector);
                playerSprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
            }
            if (event.key.code == sf::Keyboard::Key::D && event.type == sf::Event::KeyPressed)
            {
                vector.x += movement;
                playerSprite.setPosition(vector);
                playerSprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
            }*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            vector.y += movement;
            playerSprite.setPosition(vector);
            playerSprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            vector.y -= movement;
            playerSprite.setPosition(vector);
            playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            vector.x -= movement;
            playerSprite.setPosition(vector);
            playerSprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            vector.x += movement;
            playerSprite.setPosition(vector);
            playerSprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
        }
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}