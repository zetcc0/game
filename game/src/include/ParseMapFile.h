#pragma once
#include <string>
#include <fstream>

static const char* charsToRemove = " \t";

static enum valueType
{
	NUMBER, STRING,	ARRAY
};

class ParseMapFile
{
private:

public:
	static void ParseData(std::ifstream& file, std::string& line, std::string& variable, std::string& value);
};
