#include "AppState.h"
#include "Display.h"

void renderMenu() {
  for (int i = 0; i < 6; i++) {
    drawMenuItem(menuItems[i].c_str(), 30 + (i * 30), i == menuIndex);
  }
}

void selectMenuItem() {
  drawStatus(menuItems[menuIndex].c_str());
  // Add navigation logic here
}