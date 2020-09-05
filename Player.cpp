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


void Player::stopLeft(int Pos)
{
  m_Position.x = Pos;
}
void Player::stopRight(int Pos)
{
  m_Position.x = Pos - m_Position.width;
}
void Player::stopFalling(int Pos)
{
  m_Position.y = Pos - m_Position.height;
  m_OnGround = true;
}
void Player::Fall()
{
  m_OnGround = false;
}

//Get Sprite
sf::Sprite Player::getSprite()
{
  return m_Sprite;
}

float Player::getHealth()
{
  return m_Health;
}

bool Player::handleInput()
{
  m_JustJumped = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    m_JustJumped = true;
    m_IsJumping = true;
  }
  else
  {
    m_IsJumping = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    m_MovingLeft = true;
  }
  else
  {
    m_MovingLeft = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    m_MovingRight = true;
  }
  else
  {
    m_MovingRight = false;
  }

  return m_JustJumped;
}

//Other Funcs.
void Player::update(float elapsedTime, RectBound camera)
{
  //#######
  //Y Coord

  //Gravity
  m_Yvelocity += m_GravityAcceleration;
  m_Yspeed += m_GravityAcceleration;
  if (m_Yvelocity > m_MaxYvelocity)
  {m_Yvelocity = m_MaxYvelocity;}
  if (m_OnGround)
  {
    m_Yvelocity = 0; //Stop Falling
    m_CanJump = true; //Can jump
  }
  //Jump
  if (m_IsJumping && m_CanJump)
  {
    m_Yvelocity = -(m_JumpSpeed);
    m_IsJumping = true;
    m_CanJump = false;
    m_OnGround = false;
  }

  //Apply Y velocity to Y coord
  m_Position.y += m_Yvelocity * elapsedTime;

  //#######
  //X Coord

  //Move Left
  if (m_MovingLeft)
  {
    m_Xvelocity += -m_Xacceleration;
  }
  //Move Right
  if (m_MovingRight)
  {
    m_Xvelocity += m_Xacceleration;
  }

  //Maximum X velocity
  if (m_Xvelocity > m_MaxXvelocity)
  {m_Xvelocity = m_MaxXvelocity;}
  else if (m_Xvelocity < -m_MaxXvelocity)
  {m_Xvelocity = -m_MaxXvelocity;}

  //Friction
  if (!m_MovingLeft && !m_MovingRight && m_Xvelocity != 0)
  {
    if (m_Xvelocity > 0 && m_Xvelocity >= m_Xacceleration) //Right
      m_Xvelocity -= m_Xacceleration;
    else if (m_Xvelocity < 0 && m_Xvelocity <= -m_Xacceleration) //Left
      m_Xvelocity += m_Xacceleration;
    else //Stop Completely
      m_Xvelocity = 0;
  }

  //Left Screen Edge Boundaries
  if (m_MovingLeft && m_Position.x <= camera.x)
  {
    m_Xvelocity = 0;
    m_Position.x = camera.x;
  }
  //Right screen edge boundaries
  if (m_MovingRight && (m_Position.x + m_Position.width) >= (camera.x + camera.width))
  {
    m_Xvelocity = 0;
    m_Position.x = ((camera.x + camera.width) - m_Position.width);
  }

  //Apply X velocity to X coord
  m_Position.x += m_Xvelocity * elapsedTime;

  //Sprite position in relation to camera
  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);
}

void Player::draw()
{
  //######################
  //handle animation here!
  //######################
  //Animation

  //Temp Frame changer
  m_ActingFr++;
  if (m_ActingFr >= m_MaxFr)
  {
    m_ActingFr -= m_MaxFr;
  }
  SpriteAnimator(m_Sprite, m_SpriteSize, m_FramesPerRow, m_FramesPerColumn, m_ActingFr);
}
