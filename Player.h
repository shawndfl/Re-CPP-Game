#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Collisions.h"

class Player
{
  private:
    RectBound m_Position;
    RectBound m_SpriteSize;

    RectBound m_FloorBone;
    RectBound m_HeadBone;
    RectBound m_Xbone;

    sf::Sprite m_Sprite;
    int m_FramesPerRow = 10;
    int m_FramesPerColumn = 1;
    int m_MaxFr;
    int m_ActingFr;

    //X Coord Variables
    float m_Xvelocity;
    int m_MaxXvelocity = 300;
    int m_FMaxXvelocity = 450;//Will be used for speed button
    int m_Xacceleration = 100;

    //Y Coord Variables
    float m_Yvelocity;
    int m_MaxYvelocity = 700;
    int m_Yspeed;
    int m_GravityAcceleration = 62;
    int m_JumpSpeed = 600;
    bool m_canJump;

    //Status Variables
    float m_Health;
    int m_MaxHealth = 100;

    //Bool Status Variables
    bool m_movingLeft;
    bool m_movingRight;
    bool m_IsJumping;
    bool m_JustJumped;
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
    void dontJump();
    void Fall();
    void OnGround();

    //Get sprite
    sf::Sprite getSprite();

    float getHealth();

    //Other Funcs.
    bool handleInput();
    void update(RectBound tilePos, float elapsedTime, RectBound camera);
    void draw();
};

#endif
