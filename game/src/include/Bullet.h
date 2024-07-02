#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Bullet
{
private:
	float speed;
	float scale;

	sf::Vector2f direction;
	
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Bullet(const sf::Vector2f &position, const sf::Vector2f &target);
	~Bullet();

	inline const sf::FloatRect &GetBounds() { return sprite.getGlobalBounds(); }
	void Load(const sf::Vector2f& position);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

