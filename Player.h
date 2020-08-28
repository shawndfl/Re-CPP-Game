#pragma once

#include <SFML/Graphics.hpp>
#include "Collisions.h"

class Player
{
  private:
    RectBound m_Position;
    RectBound m_SpriteSize;

    sf::Sprite m_Sprite;
    int m_FramesPerRow = 10;
    int m_FramesPerColumn = 1;
    int m_MaxFr;
    int m_ActingFr;

    //X Coord Variables
    float m_Xvelocity;
    int m_MaxXvelocity = 600;
    int m_Xacceleration = 200;

    //Y Coord Variables
    float m_Yvelocity;
    int m_MaxYvelocity = 700;
    int m_Yspeed;
    int m_GravityAcceleration = 62;
    int m_JumpSpeed = 600;
    bool m_canJump;

    //Status Variables
    int m_Health;
    int m_MaxHealth = 100;

    //Bool Status Variables
    bool m_movingLeft;
    bool m_movingRight;
    bool m_jumping;
    bool m_OnGround;

  public:
    Player();

    RectBound getPos();
    RectBound getSpriteSize();

    //X Coord Funcs.
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();

    //Y Coord Funcs.
    void Jump();
    void Fall();
    void OnGround();

    //Get sprite
    sf::Sprite getSprite();

    //Other Funcs.
    void update(float elapsedTime);
    void draw();
};
