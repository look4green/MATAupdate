#include <Arduino.h>
#include "AppState.h"

// ✅ Define globals here, only once
AppState currentState = HOME;
int menuIndex = 0;

void setAppState(AppState newState) {
  currentState = newState;
}

const int menuSize = 6;
String menuItems[menuSize] = {
  "Status",
  "Sniff Packets",
  "Deauth Attack",
  "Jamming",
  "Replay",
  "Diagnostics"
};