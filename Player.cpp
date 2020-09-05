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
  m_IsJumping = true;
}
void Player::dontJump()
{
  m_IsJumping = false;
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
    m_movingLeft = true;
  }
  else
  {
    m_movingLeft = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    m_movingRight = true;
  }
  else
  {
    m_movingRight = false;
  }

  return m_JustJumped;
}

//Other Funcs.
void Player::update(RectBound tilePos, float elapsedTime, RectBound camera)
{
  //#######
  //Y Coord

  //Gravity
  m_Yvelocity += m_GravityAcceleration;
  m_Yspeed += m_GravityAcceleration;
  if (m_Yvelocity > m_MaxYvelocity)
  {m_Yvelocity = m_MaxYvelocity;}
  if (CollisionX(tilePos, m_Xbone))
  {
    if (CollisionBottom(m_FloorBone, tilePos))
    {
      m_Yvelocity = 0; //Stop Falling
      m_Position.y = tilePos.y - m_Position.height; //Set y to ground coord
      m_canJump = true; //Can jump
    }
  }
  //Jump
  if (m_IsJumping && m_canJump)
  {
    m_Yvelocity = -(m_JumpSpeed);
    m_IsJumping = true;
    m_canJump = false;
    m_OnGround = false;
  }

  //Apply Y velocity
  m_Position.y += m_Yvelocity * elapsedTime;

  m_HeadBone.y = m_Position.y;
  m_HeadBone.height = 4;
  m_FloorBone.y = (m_Position.y + m_Position.height) - 4;
  m_FloorBone.height = 4;

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

  //Maximum X velocity
  if (m_Xvelocity > m_MaxXvelocity)
  {m_Xvelocity = m_MaxXvelocity;}
  else if (m_Xvelocity < -m_MaxXvelocity)
  {m_Xvelocity = -m_MaxXvelocity;}

  //Friction
  if (!m_movingLeft && !m_movingRight && m_Xvelocity != 0)
  {
    if (m_Xvelocity > 0 && m_Xvelocity >= m_Xacceleration) //Right
      m_Xvelocity -= m_Xacceleration;
    else if (m_Xvelocity < 0 && m_Xvelocity <= -m_Xacceleration) //Left
      m_Xvelocity += m_Xacceleration;
    else //Stop Completely
      m_Xvelocity = 0;
  }

  //Left Screen Edge Boundaries
  if (m_movingLeft && m_Xbone.x <= camera.x)
  {
    m_Xvelocity = 0;
    m_Xbone.x = camera.x;
    m_Position.x = m_Xbone.x - 4;
  }
  //Right screen edge boundaries
  if (m_movingRight && (m_Xbone.x + m_Xbone.width) >= (camera.x + camera.width))
  {
    m_Xvelocity = 0;
    m_Position.x = ((camera.x + camera.width) - m_Xbone.width);
  }

  //Apply X velocity to X coord
  m_Position.x += m_Xvelocity * elapsedTime;

  m_Xbone.x = m_Position.x + 4;
  m_Xbone.width = m_Position.width - 4;
  m_Xbone.y = m_Position.y + 4;
  m_Xbone.height = m_Position.height - 4;

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
