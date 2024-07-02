#include "include/Bullet.h"
#include "include/Math.h"



Bullet::Bullet(const sf::Vector2f &position, const sf::Vector2f &target) :
	speed(0.7f),
	scale(4)
{
	direction = target - position;
	direction = Math::normalizeVector(direction);
}

Bullet::~Bullet()
{
}

void Bullet::Load(const sf::Vector2f& position)
{
	// ./assets/player/textures/playerspritesheet.png
	//./assets/bullet/textures/bullet2.png
	if (texture.loadFromFile("./assets/bullet/textures/bullet.png"))
	{
		sprite.setTexture(texture);
	}
	else
	{
		std::cout << "Load bullet sprite unsuccessfully" << std::endl;
	}

	sprite.setPosition(position);
	sprite.setScale(sf::Vector2f(scale, scale));
}

void Bullet::Update(float deltaTime)
{
	sprite.setPosition(sprite.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
