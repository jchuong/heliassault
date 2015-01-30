#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <deque>
#include "game.h"
#include "heli.h"
#include "building.h"

// TODO: Debug stream
#include <iostream>

Helicopter* Player;
std::deque<Building> LowerBuildings;
const unsigned ORIGINAL_WIDTH = 700;
const unsigned ORIGINAL_HEIGHT = 500;

void Initialize_Game(void) {
  Player = new Helicopter(100, 300, 100);
  srand(time(0));
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
    sf::RectangleShape buildingShape(sf::Vector2f(ORIGINAL_WIDTH / 10, building.height));
    buildingShape.setFillColor(sf::Color(0, 0, 100));
    buildingShape.setPosition(building.x, building.y);
    buildingShape.setOutlineColor(sf::Color(0, 0, 0));
    buildingShape.setOutlineThickness(1);
    window.draw(buildingShape);
  }
}

// Checks if buildings collide with player
// TODO: Check for bullets
void Collision_Check_Buildings(void)
{
  // Figure out where the helicopter is
  // Check the buildings within the same x area to save computation
  unsigned x, y;
  Player->Get_Location(&x, &y);
  int right = x + 70;
  int bottom = y + 40;
  if (LowerBuildings.size() < 10) // Not a screen full of buildings, just check all buildings
  {
    for (unsigned i = 0; i < LowerBuildings.size(); ++i)
    {
      if (LowerBuildings.at(i).x < right)
      {
        if (LowerBuildings.at(i).y < bottom)
        {
          // Collision, game over
          assert(false);
        }
      }
    }
  }
  else
  {
    unsigned buildingIndex = std::max(right / (ORIGINAL_WIDTH / 10), (unsigned)0);
    for (unsigned i = 0; i < std::min((unsigned)LowerBuildings.size() - buildingIndex, (unsigned)3); ++i)
    {
      if (LowerBuildings.at(i + buildingIndex).x < right)
      {
        if (LowerBuildings.at(i + buildingIndex).y < bottom)
        {
          // Collision, game over
          assert(false);
        }
      }
    }
  }
}

void Create_Building(void)
{
  unsigned height(0);
  if (LowerBuildings.size() > 0)
  {
    Building lastBuilding = LowerBuildings.back();
    if (lastBuilding.x > (int)(ORIGINAL_WIDTH - (ORIGINAL_WIDTH / 10)))
    {
      // Foremost building is not out of the screen yet, there is no space for a new one
      return;
    }
    // Try to model height around the last building
    height = (rand() % 50 - rand() % 50 + lastBuilding.height) % (unsigned)(ORIGINAL_HEIGHT * 0.65);
    if (height <= 0)
    {
      height = -height + 50;
    }
  }
  else
  {
    height = rand() % (unsigned)(ORIGINAL_HEIGHT * 0.65) + (unsigned)(ORIGINAL_HEIGHT * 0.10);
  }
  Building newBuilding(ORIGINAL_WIDTH, ORIGINAL_HEIGHT - height, height);
  LowerBuildings.push_back(newBuilding);
}

void Move_Buildings(void)
{
  // We should have created a building before this is called
  // Otherwise, we will null pointer exception, for the cost of not checking if LowerBuildings is not empty
  for (unsigned i = 0; i < LowerBuildings.size(); ++i)
  {
    LowerBuildings.at(i).x -= 1;
  }
  if (LowerBuildings.front().x <= -(int)ORIGINAL_WIDTH / 10)
  {
    LowerBuildings.pop_front();
  }
  Collision_Check_Buildings();
}

int main(void)
{
  sf::RenderWindow window(sf::VideoMode(ORIGINAL_WIDTH, ORIGINAL_HEIGHT), "Heli-Assault");
  window.setFramerateLimit(120);
  Initialize_Game();
  enum BUTTON_STATE move_state = NONE;
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
      else if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Left)
        {
          move_state = move_state | LEFT;
        }
        if (event.key.code == sf::Keyboard::Right)
        {
          move_state = move_state | RIGHT;
        }
        if (event.key.code == sf::Keyboard::Up)
        {
          move_state = move_state | UP;
        }
        if (event.key.code == sf::Keyboard::Down)
        {
          move_state = move_state | DOWN;
        }
        if (event.key.code == sf::Keyboard::Space)
        {
          Player->Shoot();
        }
      }
      else if (event.type == sf::Event::KeyReleased)
      {
        if (event.key.code == sf::Keyboard::Right)
        {
          if (move_state & RIGHT)
          {
            move_state = move_state ^ RIGHT;
          }
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
          if (move_state & LEFT)
          {
            move_state = move_state ^ LEFT;
          }
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
          if (move_state & UP)
          {
            move_state = move_state ^ UP;
          }
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
          if (move_state & DOWN)
          {
            move_state = move_state ^ DOWN;
          }
        }
      }
    }
    Player->Update_Speed(move_state);
    Player->Update_Location();
    window.clear();
    Draw_Background(window);
    Draw_Buildings(window);
    Draw_Player(window);
    window.display();
  }
  return 0;
}
