#include <SFML/Graphics.hpp>
#include "Game.h"

int main ()
{

  Game game;

  sf::RenderWindow window;
  window.create(sf::VideoMode(200, 200), "My window");

  //Main Game Loop
  while(window.isOpen())
  {

    //If widow is closed, close window
    sf::Event event;
    while (window.pollEvent(event))
    { if (event.type == sf::Event::Closed) window.close(); }

    //##############
    // Handle Input
    //##############
    game.handleInput();

    //##############
    // Update
    //##############
    game.update();

    //##############
    // Draw
    //##############
    game.draw(window);

  }

  return 0;
}
