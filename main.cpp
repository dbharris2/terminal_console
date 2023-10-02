#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "snake_game_factory.h"

int main()
{
  srand(time(NULL));

  Menu menu;

  while (true)
  {
    menu.render();

    int selectedItem = menu.selectedItem();
    if (selectedItem == 0) // Quit
    {
      break;
    }
    else if (selectedItem == 1) // Snake
    {
      SnakeGameFactory snakeGameFactory;
      snakeGameFactory.run();
    }
  }

  return 0;
}