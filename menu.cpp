#include "menu.h"

#include <iostream>

Menu::Menu()
{
  _selectedItem = 0;
}

void Menu::render()
{
  system("cls");
  std::cout << "Welcome!" << std::endl;
  std::cout << "Choose an item:" << std::endl;
  std::cout << "0: Quit" << std::endl;
  std::cout << "1: Snake" << std::endl;
  std::cin >> _selectedItem;
}

int Menu::selectedItem()
{
  return _selectedItem;
}
