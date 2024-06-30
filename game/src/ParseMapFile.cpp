#include "include/ParseMapFile.h"
#include <iostream>


static void remove_chars_from_string(std::string& str, const char* charsToRemove)
{
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i)
	{
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}


static void get_string_from_file(std::string& value)
{
	size_t countQuote = value.find("\"");
	size_t countUnquote = value.find("\"", countQuote + 1);

	value = value.substr(countQuote + 1, countUnquote - countQuote - 1);
}


static void get_array_from_file(std::string& value, std::ifstream& file)
{
	remove_chars_from_string(value, charsToRemove);

	int count = 0;

	count = value.find("{");
	value = value.substr(count + 1, value.length() - count);

	count = value.find("}");
	if (count != std::string::npos)
	{
		value = value.substr(0, count);
	}
	else
	{
		std::string actualValue;
		while (std::getline(file, actualValue))
		{
			remove_chars_from_string(actualValue, charsToRemove);

			count = actualValue.find("}");
			if (count != std::string::npos)
			{
				value.append(actualValue.substr(0, count));
				break;
			}
			value.append(actualValue);
		}
	}
}


static valueType parse_value_type(std::string& value)
{
	bool isString = value.find("\"") != std::string::npos;
	bool isArray = value.find("{") != std::string::npos;

	valueType type;

	//type = isString ? STRING : (isArray ? ARRAY : NUMBER);

	if (isString)
	{
		type = STRING;
	}
	else if (isArray)
	{
		type = ARRAY;
	}
	else
	{
		type = NUMBER;
	}

	return type;
}


static void parse_value(std::string& value, std::ifstream& file)
{

	valueType type = parse_value_type(value);

	switch (type)
	{
	case NUMBER:
		remove_chars_from_string(value, charsToRemove);
		break;
	case STRING:
		get_string_from_file(value);
		break;
	case ARRAY:
		get_array_from_file(value, file);
		break;
	default:
		break;
	}
}


void ParseMapFile::ParseData(std::ifstream& file, std::string& line, std::string& variable, std::string& value)
{
	size_t count = line.find("=");
	if (count != std::string::npos)
	{
		variable = line.substr(0, count);
		remove_chars_from_string(variable, charsToRemove);
		
		value = line.substr(count + 1, line.length() - count);
		parse_value(value, file);
	}
	else
	{
		std::string actualLine = line;
		remove_chars_from_string(actualLine, charsToRemove);

		if (!actualLine.empty())
		{
			std::cout << "Unexpected token = -> " << line << std::endl;
		}
	}
}