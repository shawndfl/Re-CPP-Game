#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Game.h"
#include "Player.h"

int main()
{
  GameStates GameState;
  GameState = GameStates::GAMEOVER;

  sf::Clock clock;
  sf::Time gameTimeTotal;

  TextureHolder holder;

  Player player;

  sf::RenderWindow window;
  window.create(sf::VideoMode(640, 360), "Game");
  window.setVerticalSyncEnabled(true);

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      window.close();
    }
    if (GameState == GameStates::GAMEOVER)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
      {
        GameState = GameStates::PLAYING;
      }
    }
    if (GameState == GameStates::PLAYING)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        player.Jump();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {player.moveLeft();}else{player.stopLeft();}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {player.moveRight();}else{player.stopRight();}

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
      {
        GameState = GameStates::PAUSED;
      }
    }
    if (GameState == GameStates::PAUSED)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
      {
        GameState = GameStates::PLAYING;
      }
    }

    //##############
    // Update
    //##############

    //Get time last frame took to execute
    sf::Time dt = clock.restart();

    //Update the total game time
    gameTimeTotal += dt;

    //Make a decimal fraction of 1 from the delta time
    float dtAsSeconds = dt.asSeconds();

    if (GameState == GameStates::PLAYING)
    {
      player.update(dtAsSeconds);
    }

    //##############
    // Draw
    //##############
    window.clear();

    //Draw Everything Here
    if (GameState == GameStates::PLAYING)
    {
      window.draw(player.getSprite());
    }

    window.display();

  }

  return 0;
}
