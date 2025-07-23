#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

// Menu interaction
void initMenu();
void updateMenu();
void renderMenu();
void nextMenuItem();
void prevMenuItem();
void selectMenuItem();
int getMenuIndex();
void setMenuIndex(int index);

#endif
