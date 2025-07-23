#ifndef APPSTATE_H
#define APPSTATE_H

#include <Arduino.h>  // ✅ Required for String

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
  DIAGNOSTICS,
};

extern AppState currentState;
extern String menuItems[];
extern int menuIndex;

void setAppState(AppState newState);

#endif