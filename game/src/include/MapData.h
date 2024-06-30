#pragma once
#include <string>

struct MapData
{
	std::string tileSheetFilepath = "";
	std::string name = "";

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleY = 0;
	int scaleX = 0;

	size_t dataSize = 0;
	int* data = nullptr;

};