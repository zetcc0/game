#include "include/Bullet.h"
#include "include/Math.h"

Bullet::Bullet(const sf::Vector2f &position, const sf::Vector2f &target) :
	speed(1.2f)
{
	circleShape.setRadius(15);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(position);

	direction = target - position;
	direction = Math::normalizeVector(direction);
}

Bullet::~Bullet()
{
}

void Bullet::Load()
{
}

void Bullet::Update(float deltaTime)
{
	circleShape.setPosition(circleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window)
{
	window.draw(circleShape);
}
