#include "include/MapLoader.h"
#include "include/MapData.h"
#include "include/ParseMapFile.h"
#include <fstream>



void MapLoader::data_to_mapdata(std::string& variable, std::string& value, MapData& mapData)
{
	if (variable == "tileSheetFilepath")
	{
		mapData.tileSheetFilepath = value;
	}
	else if (variable == "name")
	{
		mapData.name = value;

	}
	else if (variable == "tileWidth")
	{
		mapData.tileWidth = std::stoi(value);
	}
	else if (variable == "tileHeight")
	{
		mapData.tileHeight = std::stoi(value);
	}
	else if (variable == "scaleX")
	{
		mapData.scaleX = std::stoi(value);
	}
	else if (variable == "scaleY")
	{
		mapData.scaleY = std::stoi(value);
	}
	else if (variable == "dataSize")
	{
		mapData.dataSize = std::stol(value);
	}
	else if (variable == "data")
	{
		mapData.data = new int[mapData.dataSize];
		for (int i = 0; i < mapData.dataSize - 1; i++)
		{	
			int count = value.find(",");
			mapData.data[i] = stoi(value.substr(0, count + 1));
			value = value.substr(count + 1, value.length());
		}
		mapData.data[mapData.dataSize-1] = stoi(value);

		for (int i = 0; i < mapData.dataSize; i++)
		{
			std::cout << "value: " << mapData.data[i] << std::endl;
			std::cout << "type: " << typeid(mapData.data[i]).name() << "Id: " << i << std::endl;
		}
	}
}

void MapLoader::Load(std::string filepath, MapData& mapData)
{
	std::string line;
	std::ifstream file(filepath);


	if (file.is_open())
	{
		std::getline(file, line);
		if (line.find("[Map]") != std::string::npos)
		{
			while (std::getline(file, line))
			{
				std::string variable;
				std::string value;
				ParseMapFile::ParseData(file, line, variable, value);
				std::cout << variable << "=" << value << std::endl;
				data_to_mapdata(variable, value, mapData);
			}
		}
		else
		{
			std::cout << "Invalid Header [Map] -> " << line << std::endl;
		}
		
	}
	else
	{
		std::cout << "File could not open";
	}
}
