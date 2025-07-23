#include "AppState.h"

// Global variable definitions
AppState currentState = HOME;
int menuIndex = 0;
const int menuSize = 6;

String menuItems[menuSize] = {
  "Status",
  "Sniff Packets",
  "Deauth Attack",
  "Jamming",
  "Replay",
  "Diagnostics"
};

void setAppState(AppState newState) {
  currentState = newState;
}
