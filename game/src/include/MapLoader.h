#pragma once
#include <iostream>
#include "MapData.h"

class MapLoader
{
private:
	void data_to_mapdata(std::string& variable, std::string& value, MapData& mapData);

public:
	void Load(std::string filepath, MapData& mapData);
};

