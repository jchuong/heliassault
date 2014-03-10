#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "heli.h"

int main(void)
{
  // TODO
  sf::RenderWindow window(sf::VideoMode(700, 500), "Heli-Assault");
  window.setFramerateLimit(120);
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
    window.display();
  }
  return 0;
}
