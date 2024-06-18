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
	if (this->font.loadFromFile("Assets/Fonts/fontFrameRate.ttf"))
		this->frameRateText.setFont(this->font);
}

void FrameRate::Update()
{
	this->deltaTimeTimer = clock.restart();
	this->deltaTime = this->deltaTimeTimer.asMicroseconds() / 1000.0f;
	this->timer += this->deltaTime;

	if (this->timer >= 100.0)
	{
		this->frameRateText.setString("FPS: " + std::to_string((int)(1000.0f / this->deltaTime)) + "\n" + "FRAME TIME: " + std::to_string((int)this->deltaTime));
		this->timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(this->frameRateText);
}

double FrameRate::GetDeltaTime()
{
	return this->deltaTime;
}
