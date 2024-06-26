#pragma once
#include <iostream>

#include "Skeleton.h"
#include "Bullet.h"


class Player 
{
private:
	float speed;
	float bulletFireRate;

	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<Bullet> bullets;

public:
	Player();
	~Player();

	void Initialize();
	void Load();
	void Update(Skeleton &skeleton, sf::RenderWindow& window, sf::Vector2f mousePosition, float deltaTime);
	void Draw(sf::RenderWindow &window);
};

