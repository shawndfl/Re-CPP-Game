#include "TextureHolder.h"
#include "SpriteAnimator.h"
#include "Player.h"

Player::Player()
{
  m_Sprite.setTexture(TextureHolder::GetTexture("assets/Player/Sheet Test.png"));
  m_SpriteSize.width = 24;
  m_SpriteSize.height = 24;
  m_ActingFr = 0;

  m_Xvelocity = 0;
  m_Yvelocity = 0;

  m_Position.x = 0;
  m_Position.y = 0;

  m_Health = m_MaxHealth;
}

RectBound Player::getPos()
{
  return m_Position;
}
RectBound Player::getSpriteSize()
{
  return m_SpriteSize;
}

//X Coord Funcs.
void Player::moveLeft()
{
  m_movingLeft = true;
}
void Player::moveRight()
{
  m_movingRight = true;
}
void Player::stopLeft()
{
  m_movingLeft = false;
}
void Player::stopRight()
{
  m_movingRight = false;
}

//Y Coord Funcs.
void Player::Jump()
{
  m_jumping = true;
}
void Player::Fall()
{
  m_OnGround = false;
}
void Player::OnGround()
{
  m_OnGround = true;
}

//Get Sprite
sf::Sprite Player::getSprite()
{
  return m_Sprite;
}

//Other Funcs.
void Player::update(float elapsedTime)
{
  //Move Left
  if (m_movingLeft)
  {
    m_Xvelocity += -m_Xacceleration;
  }
  //Move Right
  if (m_movingRight)
  {
    m_Xvelocity += m_Xacceleration;
  }

  //X velocity caps
  if (m_Xvelocity > m_MaxXvelocity)
  {m_Xvelocity = m_MaxXvelocity;}
  else if (m_Xvelocity < -m_MaxXvelocity)
  {m_Xvelocity = -m_MaxXvelocity;}

  if (!m_movingLeft && !m_movingRight && m_Xvelocity != 0)
  {
    if (m_Xvelocity > 0 && m_Xvelocity >= m_Xacceleration)
      m_Xvelocity -= m_Xacceleration;
    else if (m_Xvelocity < 0 && m_Xvelocity <= -m_Xacceleration)
      m_Xvelocity += m_Xacceleration;
    else
      m_Xvelocity = 0;
  }

  //Apply X velocity to X coord
  m_Position.x += m_Xvelocity * elapsedTime;

  //Gravity
  //m_Yvelocity += m_GravityAcceleration;
  //m_Yspeed += m_GravityAcceleration;
  //Jump
  if (m_jumping && m_canJump)
  {
    m_canJump = false;
    m_Yvelocity = -(m_JumpSpeed);
    m_OnGround = false;
  }

  //Apply Y velocity
  m_Position.y += m_Yvelocity;

  m_Sprite.setPosition(sf::Vector2f(m_Position.x, m_Position.y));
  SpriteAnimator(m_Sprite, m_SpriteSize.width, m_SpriteSize.height, m_FramesPerRow, m_FramesPerColumn, m_ActingFr);
}
