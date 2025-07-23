#include "Display.h"
#include "Menu.h"
#include "AppState.h"
#include "Bluetooth.h"
#include "Diagnostics.h"
#include "Settings.h"
#include "ProfileSelector.h"
#include "PowerManager.h"
#include "RF.h"
#include "PluginManager.h"

// Current state tracking
AppState currentState = HOME;

void setup() {
  initDisplay();
  clearScreen();
  drawStatus("Welcome to MATA");
  delay(1000);
}

void loop() {
  switch (currentState) {
    case HOME:
      updateMenu();
      break;
    case DIAGNOSTICS:
      updateDiagnostics();
      break;
    case SETTINGS_PANEL:
      updateSettingsPanel();
      break;
    case PROFILE_PANEL:
      updateProfileSelector();
      break;
    case PLUGIN_PANEL:
      updatePlugins();
      break;
    case POWER_PANEL:
      updatePowerManager();
      break;
    case BLUETOOTH_PANEL:
      updateBluetooth();
      break;
    case RF_PANEL:
      updateRF();
      break;
  }
}