#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	int health;

	sf::Text healthText;
	sf::Font font;
	
	sf::Texture texture;

public:
	sf::Sprite sprite;

public:
	Skeleton();
	~Skeleton();
	
	void ChangeHealth(int hp);
	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow &window);
};

