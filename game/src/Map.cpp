#include "Include/Map.h"
#include "iostream"

Map::Map() :
	totalTilesY(0), totalTilesX(0), 
	tiles(nullptr), mapSprites(nullptr)
{	
}

Map::~Map()
{
	delete[] mapSprites;
	delete[] tiles;
}

void Map::Load()
{
	mapLoader.Load("./assets/maps/example.mymap", mapData);
	mapSprites = new sf::Sprite[mapData.dataSize];
	
	if (tileSheetTexture.loadFromFile(mapData.tileSheetFilepath))
	{
		totalTilesY = tileSheetTexture.getSize().y / mapData.tileHeight;
		totalTilesX = tileSheetTexture.getSize().x / mapData.tileWidth;

		int totalTiles = totalTilesY * totalTilesX;

		tiles = new Tile[totalTiles];

		for (int y = 0; y < totalTilesY; y++)
		{
			for (int x = 0; x < totalTilesX; x++)
			{
				int i = x + y * totalTilesX;

				tiles[i].id = i;
				tiles[i].position = sf::Vector2i(x * mapData.tileWidth, y * mapData.tileHeight);
			}
		}

		for (int y = 0; y < mapData.mapHeight; y++)
		{
			for (int x = 0; x < mapData.mapWidth; x++)
			{
				int i = x + y * mapData.mapWidth;

				int tileIndex = mapData.data[i];

				mapSprites[i].setTexture(tileSheetTexture);

				mapSprites[i].setTextureRect(sf::IntRect(tiles[tileIndex].position.x, tiles[tileIndex].position.y, mapData.tileWidth, mapData.tileHeight));
			
				mapSprites[i].setScale(sf::Vector2f(mapData.scaleX, mapData.scaleY));

				mapSprites[i].setPosition(sf::Vector2f(x * mapData.tileWidth * mapData.scaleX, y * mapData.tileHeight * mapData.scaleY));
			}
		}
	}
	else
	{
		std::cout << "Could not Load map" << std::endl;
	}
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mapData.dataSize; i++)
		window.draw(mapSprites[i]);
}
