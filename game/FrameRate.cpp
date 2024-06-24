#include "FrameRate.h"

FrameRate::FrameRate() :
	deltaTime(0),
	timer(1000.0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (font.loadFromFile("Assets/Fonts/fontFrameRate.ttf"))
		frameRateText.setFont(font);
}

void FrameRate::Update()
{
	deltaTimeTimer = clock.restart();
	deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0f;
	timer += deltaTime;

	if (timer >= 100.0)
	{
		frameRateText.setString("FPS: " + std::to_string((int)(1000.0f / deltaTime)) + "\n" + "FRAME TIME: " + std::to_string((int)deltaTime));
		timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}

double FrameRate::GetDeltaTime()
{
	return deltaTime;
}
