#include "Skeleton.h"

void Skeleton::Initialize()
{
    this->sprite.setPosition(sf::Vector2f(100, 100));
    this->sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}

void Skeleton::Load()
{
    if (this->texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
        this->sprite.setTexture(this->texture);
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}
