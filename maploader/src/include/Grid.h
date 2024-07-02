#pragma once

#include <SFML/Graphics.hpp>

class Grid
{
private:
	int lineThickness;
	sf::Vector2f position;
	
	sf::Vector2i cellSize;
	sf::Vector2i totalCells;
	sf::Vector2i lineLength;

	sf::RectangleShape* hLine;
	sf::RectangleShape* vLine;

public:
	Grid(const sf::Vector2f& position, const sf::Vector2i& totalCells, const sf::Vector2i& cellSize, int lineThickness);
	~Grid();

	void Load();
	void Draw(sf::RenderWindow &window);
};

