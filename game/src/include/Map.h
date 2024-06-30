#pragma once
#include "Tile.h"
#include "MapData.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	Tile* tiles;

	int totalTilesY;
	int totalTilesX;

	int tileHeight;
	int tileWidth;

	static const int MAP_SIZE = 36;
	const int MAP_WIDTH = 6;
	const int MAP_HEIGHT = 6;

	int mapIds[MAP_SIZE] = {
		2, 3, 3, 3, 3, 4,
		26, 1, 1, 1, 1, 26,
		26, 1, 1, 1, 1, 26,
		26, 1, 1, 1, 1, 26,
		26, 1, 1, 1, 1, 26,
		50, 24, 24, 24, 24, 50
	};

	sf::Sprite mapSprites[MAP_SIZE];

public:
	Map();
	~Map();

	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
};

