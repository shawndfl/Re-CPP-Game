#pragma once
#include <SFML/Graphics.hpp>
#include "Collisions.h"
#include "TextureHolder.h"

enum class tileTypes { air, ground, roof, wall };

class Tile
{
  private:
    sf::Sprite m_Sprite;

    RectBound m_Position;
    tileTypes m_TileType;

    int m_FrTilesPerRow = 5;
    int m_FrTilesPerColumn = 1;

  public:
    Tile();

    void setPos(int x, int y);
    RectBound getPos();
    void setType(int ID);
    tileTypes getType();

    void update(RectBound tilePosition, RectBound camera);
    void draw();

    sf::Sprite getSprite();
};
