#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cassert>
#include "heli.h"

#include <iostream>
Helicopter* Player;
const unsigned ORIGINAL_WIDTH = 700;
const unsigned ORIGINAL_HEIGHT = 500;
double scale = 1.0;

void Initialize_Game(void)
{
  Player = new Helicopter(100, 300, 100, scale);
}

void Update_Scale(unsigned new_width)
{
  scale = new_width / (double)ORIGINAL_WIDTH;
  assert(Player != 0);
  Player->Set_Scale(scale);
}

void Draw_Background(sf::RenderWindow& window)
{
  sf::RectangleShape background(sf::Vector2f(ORIGINAL_WIDTH * scale, ORIGINAL_HEIGHT * scale));
  background.setFillColor(sf::Color(255, 255, 255));
  window.draw(background);
}

void Draw_Player(sf::RenderWindow& window)
{
  
}

int main(void)
{
  // TODO
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
      else if (event.type == sf::Event::Resized)
      {
        Update_Scale(window.getSize().x);
      }
    }
    window.clear();
    Draw_Background(window);
    Draw_Player(window);
    window.display();
  }
  return 0;
}
