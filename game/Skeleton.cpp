#include "Includes/Skeleton.h"

Skeleton::Skeleton() :
    health(100)
{
    sprite.setPosition(sf::Vector2f(300, 300));
    sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    
}

Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
        sprite.setTexture(texture);
    if (font.loadFromFile("Assets/Fonts/fontFrameRate.ttf"))
    {
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    }
}

void Skeleton::Update()
{
    healthText.setPosition(sprite.getPosition() + sf::Vector2f(10, -20));
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(healthText);
}
