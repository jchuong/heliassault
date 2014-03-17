#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cassert>
#include "heli.h"

#include <iostream>
Helicopter* Player;
const unsigned ORIGINAL_WIDTH = 700;
const unsigned ORIGINAL_HEIGHT = 500;

void Initialize_Game(void)
{
  Player = new Helicopter(100, 300, 100);
}

void Draw_Background(sf::RenderWindow& window)
{
  sf::RectangleShape background(sf::Vector2f(ORIGINAL_WIDTH, ORIGINAL_HEIGHT));
  background.setFillColor(sf::Color(255, 255, 255));
  window.draw(background);
}

void Draw_Player(sf::RenderWindow& window)
{
  assert(Player != 0);
  unsigned x, y;
  Player->Get_Location(&x, &y);
  sf::RectangleShape helicopter(sf::Vector2f(70, 40));
  helicopter.setFillColor(sf::Color(0, 0, 255));
  helicopter.setPosition(x, y);
  window.draw(helicopter);
}

int main(void)
{
  sf::RenderWindow window(sf::VideoMode(ORIGINAL_WIDTH, ORIGINAL_HEIGHT), "Heli-Assault");
  window.setFramerateLimit(120);
  Initialize_Game();
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear();
    Draw_Background(window);
    Draw_Player(window);
    window.display();
  }
  return 0;
}
