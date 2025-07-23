#include "Menu.h"
#include "Display.h"
#include "AppState.h"
#include "Encoder.h"
#include "Touchscreen.h"
#include "InputHandler.h"
#include "ThemeManager.h"

void initMenu() {
  menuIndex = 0;
}

void renderMenu() {
  Theme theme = getCurrentTheme();
  clearScreen();
  drawTitleBar("Main Menu");

  for (int i = 0; i < menuSize; i++) {
    int y = 40 + (i * theme.spacingY);
    drawMenuItem(menuItems[i].c_str(), y, i == menuIndex);
  }
}

void updateMenu() {
  renderMenu();

  if (encoderMoved()) {
    if (encoderDirection() > 0) nextMenuItem();
    else prevMenuItem();
    delay(150);
  }

  if (encoderClicked() || touchClicked()) {
    selectMenuItem();
    resetInactivityTimer();
  }
}

int getMenuIndex() {
  return menuIndex;
}

void setMenuIndex(int index) {
  menuIndex = constrain(index, 0, menuSize - 1);
}

void nextMenuItem() {
  menuIndex = (menuIndex + 1) % menuSize;
}

void prevMenuItem() {
  menuIndex = (menuIndex - 1 + menuSize) % menuSize;
}

void selectMenuItem() {
  switch (menuIndex) {
    case 0: setAppState(STATUS_SCREEN);    break;
    case 1: setAppState(PACKET_SNIFF);     break;
    case 2: setAppState(DEAUTH_ATTACK);    break;
    case 3: setAppState(JAM_MODE);         break;
    case 4: setAppState(REPLAY_MODE);      break;
    case 5: setAppState(DIAGNOSTICS);      break;
  }
}
