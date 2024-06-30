#pragma once
#include "Tile.h"
#include "MapLoader.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	Tile* tiles;

	MapData mapData;
	MapLoader mapLoader;

	int totalTilesY;
	int totalTilesX;

	sf::Sprite* mapSprites;

public:
	Map();
	~Map();

	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

