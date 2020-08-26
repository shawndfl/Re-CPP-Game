#include <SFML/Graphics.hpp>

int main ()
{

  sf::Window window;
  window.create(sf::VideoMode(800, 600), "My window");

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

    //##############
    // Update
    //##############

    //##############
    // Draw
    //##############

  }

  return 0;
}
