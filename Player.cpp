#include "TextureHolder.h"
#include "SpriteAnimator.h"
#include "Player.h"

Player::Player()
{
  m_Sprite.setTexture(TextureHolder::GetTexture("assets/Player/Sheet Test.png"));
  m_SpriteSize.width = 24;
  m_SpriteSize.height = 24;

  //Change Later!
  m_Position.width = m_SpriteSize.width;
  m_Position.height = m_SpriteSize.height;

  m_MaxFr = m_FramesPerRow * m_FramesPerColumn;
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
  m_jumping = false;
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
void Player::update(float elapsedTime, RectBound camera)
{
  //#######
  //X Coord

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

  //#######
  //Y Coord

  //Gravity
  m_Yvelocity += m_GravityAcceleration;
  m_Yspeed += m_GravityAcceleration;
  if (m_Yvelocity > m_MaxYvelocity)
  {m_Yvelocity = m_MaxYvelocity;}
  if (m_Position.y >= 144 - m_Position.height/*m_OnGround*/)
  {
    m_Yvelocity = 0; //Stop Falling
    m_Position.y = 144 - m_Position.height; //Set y to ground coord
    m_canJump = true; //Can jump
  }
  //Jump
  if (m_jumping && m_canJump)
  {
    m_jumping = true;
    m_canJump = false;
    m_Yvelocity = -(m_JumpSpeed);
    m_OnGround = false;
  }

  //Apply Y velocity
  m_Position.y += m_Yvelocity * elapsedTime;

  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);
}

void Player::draw()
{
  //######################
  //handle animation here!
  //######################
  //Sprite position in relation to camera
  //Animation

  //Temp Frame changer
  m_ActingFr++;
  if (m_ActingFr >= m_MaxFr)
  {
    m_ActingFr -= m_MaxFr;
  }
  SpriteAnimator(m_Sprite, m_SpriteSize, m_FramesPerRow, m_FramesPerColumn, m_ActingFr);
}
