#include "Encoder.h"
#include "AppState.h"
#include "Display.h"

// Encoder-only rendering (if needed outside the menu system)
void renderMenu() {
  for (int i = 0; i < menuSize; i++) {
    drawMenuItem(menuItems[i].c_str(), 30 + (i * 30), i == menuIndex);
  }
}

// Optional direct action if not using Menu.cpp
void selectMenuItem() {
  drawStatus(menuItems[menuIndex].c_str()); // Placeholder or preview
}
