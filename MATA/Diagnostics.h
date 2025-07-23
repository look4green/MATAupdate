#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <Arduino.h>

// MATA diagnostics and signal tools
void updateDiagnostics();
void updateSettingsPanel();
void updateRF();

// RSSI visualization and module presence checks

void showSignalStrength();     // Display live RSSI bar graph
bool checkModuleStatus();      // Validate connected modules

#endif
