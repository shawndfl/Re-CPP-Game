#include "HealthBar.h"

void HealthBar::update(float health)
{
  m_HealthBar.setSize(sf::Vector2f((health / 100) * 100, 6));
  m_HealthBar.setPosition(sf::Vector2f(8, 8));
  m_HealthBar.setFillColor(sf::Color(255, 0, 0));
  m_HealthBar.setOutlineColor(sf::Color(255, 255, 255));
  m_HealthBar.setOutlineThickness(1);

}

sf::RectangleShape HealthBar::getHealthBar()
{
  return m_HealthBar;
}
