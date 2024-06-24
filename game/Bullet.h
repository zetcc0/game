#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float speed;

	sf::Vector2f direction;

	sf::CircleShape circleShape;

public:
	Bullet(const sf::Vector2f &position, const sf::Vector2f &target);
	~Bullet();

	inline const sf::FloatRect &GetBounds() { return circleShape.getGlobalBounds(); }
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

