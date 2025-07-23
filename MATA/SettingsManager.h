#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <Arduino.h>  // ✅ Required for String

String getThemeName();
void setThemeName(const String& name);

String getBootProfile();
void setBootProfile(const String& profile);

void saveSettings();

#endif
