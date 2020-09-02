#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics.hpp>

class HealthBar
{
  private:
    float health;

    sf::RectangleShape m_HealthBar;

  public:

    int length;

    void update(float health);

    sf::RectangleShape getHealthBar();
};

#endif
