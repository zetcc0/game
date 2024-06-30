#pragma once
#include <string>

struct MapData
{
	int version;

	std::string tileSheetFilepath = "";
	std::string name = "";

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleY = 0;
	int scaleX = 0;

	int mapWidth = 0;
	int mapHeight = 0;
	size_t dataSize = 0;
	int* data = nullptr;

};