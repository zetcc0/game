#include "Includes/Player.h"
#include "Includes/Math.h"

Player::Player() :
    speed(1),
    bulletFireRate(0)
{
}


Player::~Player()
{
}

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/playerspritesheet.png"))
        sprite.setTexture(texture);

    sprite.setPosition(sf::Vector2f(100, 100));
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void Player::Update(Skeleton &skeleton, sf::RenderWindow &window, sf::Vector2f mousePosition, float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(0, speed) * deltaTime);
        sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(0, -speed) * deltaTime);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(-speed, 0) * deltaTime);
        sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(speed, 0) * deltaTime);
        sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
    }

    bulletFireRate += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && bulletFireRate >= 250.0)
    {
        
        Bullet bullet(sprite.getPosition(), mousePosition);
        bullets.push_back(bullet);
        bulletFireRate = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        
        bullets[i].Update(deltaTime);
        if (bullets[i].GetBounds().intersects(skeleton.sprite.getGlobalBounds()))
        {
            bullets.erase(std::next(bullets.begin(), i));
            skeleton.ChangeHealth(-10);
        }
    }
}


void Player::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }
}
