#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include "Tile.h"


enum class GameStates { PLAYING, PAUSED, GAMEOVER };
int main()
{
  GameStates GameState;
  GameState = GameStates::GAMEOVER;

  sf::Clock clock;
  sf::Clock animClock;
  sf::Time gameTimeTotal;

  TextureHolder holder;

  Player player;

  //Tile Space
  int levelWidthTiles = 20;
  int levelHeightTiles = 11;
  Tile** tiles = nullptr;
  delete[] tiles;

  int levelMap[levelHeightTiles][levelWidthTiles] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                     {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,4},
                                                     {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
                                                     {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
                                                     {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4}};
   tiles = new Tile*[levelHeightTiles];
   for(int i = 0; i < levelHeightTiles; i++)
   {
     tiles[i] = new Tile[levelWidthTiles];
   }
   for (int i = 0; i < levelHeightTiles; i++)
   {
     for (int j = 0; j < levelWidthTiles; j++)
     {
       tiles[i][j].setType(levelMap[i][j]);
     }
   }


  int windowWidth = 288;
  int windowHeight = 162;
  sf::RenderWindow window;
  window.create(sf::VideoMode(windowWidth, windowHeight), "Game");
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
      {player.Jump();}else{player.Fall();}
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
    //Animation Timer! Every 0.048 seconds update animations!
    if (animClock.getElapsedTime().asSeconds() > 0.048f)
    {
      //Put all animation funcs. in here!

      player.draw();
      animClock.restart();
    }

    //Draw Everything Here
    if (GameState == GameStates::PLAYING)
    {
      window.draw(player.getSprite());
    }

    window.display();

  }

  delete[] tiles;

  return 0;
}
