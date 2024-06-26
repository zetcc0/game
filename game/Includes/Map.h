#pragma once
#include "Tile.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	Tile* tiles;

	int totalTilesY;
	int totalTilesX;

	int tileHeight;
	int tileWidth;

	int mapIds[36] = {
		2, 3, 3, 3, 3, 4,
		26, 1, 1, 1, 1, 26,
		26, 1, 1, 1, 1, 26,
		26, 1, 1, 1, 1, 26,
		26, 1, 1, 1, 1, 26,
		50, 24, 24, 24, 24, 50
	};

	sf::Sprite mapSprites[36];

public:
	Map();
	~Map();

	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
};

