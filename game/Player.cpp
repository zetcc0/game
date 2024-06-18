#include "Player.h"
#include "Math.h"

Player::Player() :
    speed(1),
    bulletSpeed(0.5f),
    reload(0)
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
    if (this->texture.loadFromFile("Assets/Player/Textures/playerspritesheet.png"))
        this->sprite.setTexture(this->texture);

    this->sprite.setPosition(sf::Vector2f(100,100));
    this->sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void Player::Update(Skeleton &skeleton, float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->sprite.setPosition(this->sprite.getPosition() + sf::Vector2f(0, speed) * deltaTime);
        this->sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->sprite.setPosition(this->sprite.getPosition() + sf::Vector2f(0, -speed) * deltaTime);
        this->sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->sprite.setPosition(this->sprite.getPosition() + sf::Vector2f(-speed, 0) * deltaTime);
        this->sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->sprite.setPosition(this->sprite.getPosition() + sf::Vector2f(speed, 0) * deltaTime);
        this->sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
    }
    
    this->reload += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->reload >= 250.0)
    { 
        this->bullets.push_back(sf::CircleShape(20));
        bullets[this->bullets.size() - 1].setPosition(this->sprite.getPosition());
        this->reload = 0;
    }
    for (size_t i = 0; i < this->bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - this->bullets[i].getPosition();
        bulletDirection = Math::normalizeVector(bulletDirection);
        this->bullets[i].setPosition(this->bullets[i].getPosition() + bulletDirection * this->bulletSpeed * deltaTime);
        if (this->bullets[i].getGlobalBounds().intersects(skeleton.sprite.getGlobalBounds()))
        {
            bullets.erase(std::next(bullets.begin(), i));
        }
    }
}

void Player::Draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < this->bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
    window.draw(this->sprite);
}
