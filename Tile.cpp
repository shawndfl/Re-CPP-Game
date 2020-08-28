#include "Tile.h"
#include "SpriteAnimator.h"

Tile::Tile()
{
  m_Sprite.setTexture(TextureHolder::GetTexture("assets/Tiles.png"));

  m_Position.width = 16;
  m_Position.height = 16;
}

//Set position
void Tile::setPos(int x, int y)
{
  m_Position.x = (x * 16);
  m_Position.y = (y * 16);
}

//Get position
RectBound Tile::getPos()
{
  return m_Position;
}

void Tile::setType(int ID)
{
  if (ID == 0)
  {
    m_TileType = tileTypes::air;
    SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 0);
  }
  else if (ID == 1)
    {
      m_TileType = tileTypes::roof;
      SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 1);
    }
  else if (ID == 2)
    {
      m_TileType = tileTypes::roof;
      SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 1);
    }
  else if (ID == 3)
    {
      m_TileType = tileTypes::roof;
      SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 1);
    }
  else if (ID == 4)
    {
      m_TileType = tileTypes::ground;
      SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 2);
    }
  else if (ID == 5)
    {
      m_TileType = tileTypes::ground;
      SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 2);
    }
  else if (ID == 6)
    {
      m_TileType = tileTypes::ground;
      SpriteAnimator(m_Sprite, m_Position, m_FrTilesPerRow, m_FrTilesPerColumn, 2);
    }
}

tileTypes Tile::getType()
{
  return m_TileType;
}

void Tile::update(RectBound tilePosition, RectBound camera)
{
  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);
}

Sprite Tile::getSprite()
{
  return m_Sprite;
}
