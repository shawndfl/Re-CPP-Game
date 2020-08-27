#include <SFML/Graphics.hpp>
#include "Game.h"

void Game::draw(sf::RenderWindow &window)
{
  //Must be first
  window.clear();

  //Draw every thing here!
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  window.draw(shape);

  //Must be last
  window.display();
}
