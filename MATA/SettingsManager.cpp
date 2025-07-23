#include <Arduino.h>           // ✅ Required for String
#include "SettingsManager.h"

String currentTheme = "Default";
String bootProfile = "Standard";

String getThemeName() {
  return currentTheme;
}

void setThemeName(const String& name) {
  currentTheme = name;
}

String getBootProfile() {
  return bootProfile;
}

void setBootProfile(const String& profile) {
  bootProfile = profile;
}

void saveSettings() {
  // Add EEPROM or SD saving logic here
}