#pragma once
#include <SFML/Graphics.hpp>
#include "Collisions.h"

void SpriteAnimator(sf::Sprite& sprite, RectBound SpriteSize, int framesPerRow, int framesPerColumn, int currentFrame);
