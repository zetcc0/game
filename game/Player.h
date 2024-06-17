#pragma once
#include "Skeleton.h"

class Player 
{
private:
	sf::Texture texture;
	float speed;
	sf::Sprite sprite;
	std::vector<sf::CircleShape>  bullets;
	float bulletSpeed;

public:
	void Initialize();
	void Load();
	void Update(Skeleton &skeleton);
	void Draw(sf::RenderWindow &window);
};

