#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text frameRateText;
	sf::Font font;
	sf::Clock clock;
	sf::Time deltaTimeTimer;
	double deltaTime;
	double timer;

public:
	FrameRate();
	~FrameRate();

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);
	double GetDeltaTime();
};

