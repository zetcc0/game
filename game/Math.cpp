#include "Math.h"

sf::Vector2f Math::normalizeVector(sf::Vector2f vector)
{
    float magnitude = std::sqrtf(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector(vector.x / magnitude, vector.y / magnitude);
    return normalizedVector;
}
