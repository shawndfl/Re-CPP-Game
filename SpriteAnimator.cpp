#include "SpriteAnimator.h"

void SpriteAnimator(sf::Sprite& sprite, int spriteWidth, int spriteHeight, int framesPerRow, int framesPerColumn, int currentFrame)
{
  int spriteSheetRow = (currentFrame / framesPerRow) | 0;
  int spriteSheetColumn = (currentFrame % framesPerRow) | 0;
  int spriteSheetX = (spriteSheetColumn * spriteWidth);
  int spriteSheetY = (spriteSheetRow * spriteHeight);

  sprite.setTextureRect(sf::IntRect(spriteSheetX, spriteSheetY, spriteWidth, spriteHeight));
}
