#pragma once

class Menu
{
public:
  Menu();
  void render();
  int selectedItem();

private:
  int _selectedItem;
};