#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Collisions.h"

class Player
{
  private:
    RectBound m_Position;
    RectBound m_SpriteSize;

    Sprite m_Sprite;

    //X Coord Variables
    float m_Xvelocity;
    int m_MaxXvelocity = 6250;
    int m_Xacceleration = 625;

    //Y Coord Variables
    float m_Yvelocity;
    int m_MaxYvelocity;
    int m_Yspeed;
    int m_GravityAcceleration = 62;
    int m_JumpSpeed = 938;
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
    Sprite getSprite();

    //Other Funcs.
    void update(float elapsedTime);
};
