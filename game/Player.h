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
	double reload;

public:
	Player();
	~Player();

	void Initialize();
	void Load();
	void Update(Skeleton &skeleton, float deltaTime);
	void Draw(sf::RenderWindow &window);
};

