#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Collisions.h"
#include "Player.h"
#include "Tile.h"
#include "HealthBar.h"


enum class GameStates { GAMEOVER, PLAYING, PAUSED };
int main()
{
  GameStates GameState;
  GameState = GameStates::GAMEOVER;

  sf::Clock clock;
  sf::Clock animClock;
  sf::Time gameTimeTotal;

  TextureHolder holder;

  Player player;
  HealthBar pHealth;

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
                                                     {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,5,6},
                                                     {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
                                                     {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
                                                     {4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6}};
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
       tiles[i][j].setPos(j, i);
     }
   }


  int windowWidth = 288;
  int windowHeight = 162;
  sf::RenderWindow window;
  window.create(sf::VideoMode(windowWidth, windowHeight), "Game");
  window.setVerticalSyncEnabled(true);


  //Game over picture
  sf::Sprite gameOver;
  gameOver.setTexture(TextureHolder::GetTexture("assets/GameOver.png"));
  gameOver.setOrigin(32, 24);
  gameOver.setPosition(windowWidth / 2, windowHeight / 2);

  sf::RectangleShape background;
  background.setSize(sf::Vector2f(windowWidth, windowHeight));
  background.setFillColor(sf::Color(120, 199, 245));
  background.setPosition(0, 0);

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

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
      { GameState = GameStates::PAUSED; }

      if (player.handleInput())
      {
        //Play a jump sound
      }
    }
    if (GameState == GameStates::PAUSED)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        GameState = GameStates::PLAYING;
    }

    //##############
    // Update
    //##############

    //Get time last frame took to execute
    sf::Time dt = clock.restart();

    //Update the total game time
    gameTimeTotal += dt;

    RectBound camera;
    camera.width = windowWidth;
    camera.height = windowHeight;

    //Make a decimal fraction of 1 from the delta time
    float dtAsSeconds = dt.asSeconds();
    RectBound tilePos;

    if (GameState == GameStates::PLAYING)
    {
      for (int i = 0; i < levelHeightTiles; i++)
      {
        for (int j = 0; j < levelWidthTiles; j++)
        {
          if (Collision(tiles[i][j].getPos(), camera))
          {
            if (tiles[i][j].getType() != tileTypes::air)
            {
              tiles[i][j].update(camera);

              if (CollisionX(tiles[i][j].getPos(), player.getPos()))
              {
                if (CollisionY(player.getPos(), tiles[i][j].getPos()) && tiles[i][j].getType() == tileTypes::ground)
                {
                  tilePos = tiles[i][j].getPos();
                }
              }
            }
          }
        }
      }

      player.update(tilePos, dtAsSeconds, camera);
      pHealth.update(player.getHealth());

      //Update Camera - Must be last!

      //X coord
      if (player.getPos().x <= 100)
      {
        camera.x = 0;
      }
      else if (player.getPos().x > ((levelWidthTiles * 16) - 188))
      {
        camera.x = ((levelWidthTiles * 16) - camera.width);
      }
      else
      {
        camera.x = player.getPos().x - 100;
      }

      //Y coord
      if (player.getPos().y <= 100)
      {
        camera.y = 0;
      }
      else if (player.getPos().y > ((levelHeightTiles * 16) -62))
      {
        camera.y = ((levelHeightTiles * 16) - camera.height);
      }
      else
      {
        camera.y = player.getPos().y - 100;
      }
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

    if (GameState == GameStates::GAMEOVER)
    {
      window.draw(gameOver);
    }

    if (GameState == GameStates::PLAYING)
    {
      window.draw(background);
      for (int i = 0; i < levelHeightTiles; i++)
      {
        for (int j = 0; j < levelWidthTiles; j++)
        {
          if (Collision(tiles[i][j].getPos(), camera) && tiles[i][j].getType() != tileTypes::air)
          {
            window.draw(tiles[i][j].getSprite());
          }
        }
      }
      window.draw(pHealth.getHealthBar());
      window.draw(player.getSprite());
    }

    window.display();

  }

  delete[] tiles;

  return 0;
}
