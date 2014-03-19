#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cassert>
#include <vector>
#include "heli.h"
#include "building.h"

// TODO: Debug stream
#include <iostream>

Helicopter* Player;
std::vector<Building> LowerBuildings;
const unsigned ORIGINAL_WIDTH = 700;
const unsigned ORIGINAL_HEIGHT = 500;

void Initialize_Game(void) {
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

void Draw_Buildings(sf::RenderWindow& window)
{
  for (unsigned i = 0; i < LowerBuildings.size(); ++i)
  {
    Building building = LowerBuildings.at(i);
    sf::RectangleShape buildingShape(sf::Vector2f(ORIGINAL_WIDTH / 20, building.height));
    buildingShape.setFillColor(sf::Color(0, 0, 100));
    buildingShape.setPosition(building.x, building.y);
    buildingShape.setOutlineColor(sf::Color(0, 0, 0));
    buildingShape.setOutlineThickness(1);
    window.draw(buildingShape);
  }
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

      // Handle key input here
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        Player->Move_Left();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        Player->Move_Right();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        Player->Move_Up();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
        Player->Move_Down();
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        Player->Shoot();
      }
    }
    window.clear();
    Draw_Background(window);
    Draw_Buildings(window);
    Draw_Player(window);
    window.display();
  }
  return 0;
}
