#ifndef APPSTATE_H
#define APPSTATE_H

#include <Arduino.h>

// Enum representing different screens and states
enum AppState {
  HOME,
  SETTINGS_PANEL,
  PROFILE_PANEL,
  PLUGIN_PANEL,
  POWER_PANEL,
  BLUETOOTH_PANEL,
  RF_PANEL,
  STATUS_SCREEN,
  DEAUTH_ATTACK,
  JAM_MODE,
  PACKET_SNIFF,
  REPLAY_MODE,
  DIAGNOSTICS
};

// Global app state and menu system
extern AppState currentState;
extern int menuIndex;
extern const int menuSize;
extern String menuItems[];

void setAppState(AppState newState);

#endif
