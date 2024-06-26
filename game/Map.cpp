#include "Includes/Map.h"
#include "iostream"

Map::Map() :
	tileHeight(16), tileWidth(16), totalTilesY(0), totalTilesX(0)
{
	tiles = nullptr;
}

Map::~Map()
{
}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("Assets/Map/tileSheet.png"))
	{
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;
		totalTilesX = tileSheetTexture.getSize().x / tileWidth;

		int totalTiles = totalTilesY * totalTilesX;

		tiles = new Tile[totalTiles];

		for (int y = 0; y < totalTilesY; y++)
		{
			for (int x = 0; x < totalTilesX; x++)
			{
				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
			}
		}
	}

	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			int i = x + y * 6;

			int tileIndex = mapIds[i];

			mapSprites[i].setTexture(tileSheetTexture);
			mapSprites[i].setTextureRect(sf::IntRect(tiles[tileIndex].position.x, tiles[tileIndex].position.y, tileWidth, tileHeight));
			mapSprites[i].setScale(sf::Vector2f(5, 5));
			mapSprites[i].setPosition(sf::Vector2f(x * tileWidth * 5.f, y * tileHeight * 5.f));
		}
	}
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 36; i++)
		window.draw(mapSprites[i]);
}
