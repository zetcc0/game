#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<math.h>


sf::Vector2f normalizeVector(sf::Vector2f vector) 
{
    float magnitude = std::sqrtf(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector(vector.x / magnitude, vector.y / magnitude);
    return normalizedVector;
}

int main()
{
    // ---------------------- Creating window ---------------------- 
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana nueva pa", sf::Style::Default, settings);
    //  ---------------------- End Creating window ---------------------- 

    // ---------------------- Skeleton ---------------------- 
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    
    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
        skeletonSprite.setTexture(skeletonTexture);

    skeletonSprite.setPosition(sf::Vector2f(100,100));
    skeletonSprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    // ---------------------- End Skeleton ---------------------- 

    // ---------------------- Player ---------------------- 
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    sf::Vector2f playerPosition(100, 500);
    int playerSpeed = 1;
    
    if (playerTexture.loadFromFile("Assets/Player/Textures/playerspritesheet.png")) 
            playerSprite.setTexture(playerTexture);
    
    playerSprite.setPosition(playerPosition);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    // ---------------------- End Player ---------------------- 

    //  ---------------------- Bullet ----------------------
    std::vector<sf::CircleShape> bullets;
    float bulletSpeed = 0.5f;
    //  ---------------------- End Bullet ----------------------

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            playerPosition += sf::Vector2f(0, playerSpeed);
            playerSprite.setPosition(playerPosition);
            playerSprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            playerPosition += sf::Vector2f(0, -playerSpeed);
            playerSprite.setPosition(playerPosition);
            playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            playerPosition += sf::Vector2f(-playerSpeed, 0);
            playerSprite.setPosition(playerPosition);
            playerSprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            playerPosition += sf::Vector2f(playerSpeed, 0);
            playerSprite.setPosition(playerPosition);
            playerSprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::CircleShape(20));
            bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }
        

        window.clear(sf::Color::Black);
        for (size_t i = 0; i < bullets.size(); i++) 
        {
            window.draw(bullets[i]);
        }
        window.draw(skeletonSprite);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}