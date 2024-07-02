#include "include/Grid.h"

Grid::Grid(const sf::Vector2f& position, const sf::Vector2i& totalCells, const sf::Vector2i& cellSize, int lineThickness) :
	totalCells(totalCells), cellSize(cellSize),
	lineThickness(lineThickness), position(position),
	lineLength(sf::Vector2i(totalCells.x * this->cellSize.x + this->lineThickness, totalCells.y * this->cellSize.y))

{
	vLine = new sf::RectangleShape[this->totalCells.y+1];
	hLine = new sf::RectangleShape[this->totalCells.x+1];
	
	for (int i = 0; i <= this->totalCells.y; i++)
	{
		sf::RectangleShape line;
		line.setPosition(sf::Vector2f(0, i * this->cellSize.y) + this->position);
		line.setSize(sf::Vector2f(this->lineLength.x, this->lineThickness));
		vLine[i] = line;
	}

	for (int i = 0; i <= this->totalCells.x; i++)
	{
		sf::RectangleShape line;
		line.setPosition(sf::Vector2f(i * this->cellSize.x, 0) + this->position);
		line.setSize(sf::Vector2f(this->lineThickness, lineLength.y));
		hLine[i] = line;
	}
}

Grid::~Grid()
{
	delete[] hLine;
	delete[] vLine;
}

void Grid::Load()
{
}

void Grid::Draw(sf::RenderWindow& window)
{

	for (int i = 0; i <= totalCells.y; i++)
	{
		window.draw(vLine[i]);
	}
	for (int i = 0; i <= totalCells.x; i++)
	{
		window.draw(hLine[i]);
	}
}
