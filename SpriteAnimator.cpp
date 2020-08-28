#include "SpriteAnimator.h"

void SpriteAnimator(sf::Sprite& sprite, RectBound SpriteSize, int framesPerRow, int framesPerColumn, int currentFrame)
{
  int spriteSheetRow = (currentFrame / framesPerRow) | 0;
  int spriteSheetColumn = (currentFrame % framesPerRow) | 0;
  int spriteSheetX = (spriteSheetColumn * SpriteSize.width);
  int spriteSheetY = (spriteSheetRow * SpriteSize.height);

  sprite.setTextureRect(sf::IntRect(spriteSheetX, spriteSheetY, SpriteSize.width, SpriteSize.height));
}
