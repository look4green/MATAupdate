#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>

// Global TFT instance declaration
extern TFT_eSPI tft;

// Display initialization
void initDisplay();

// UI element rendering
void drawMenuItem(const char* label, int y, bool selected);
void drawStatus(const char* message);
void drawTitleBar(const char* title);
// Utility
void clearScreen();

void drawTitleBar(const char* title);
void drawRSSIBars(int rssi);

#endif // DISPLAY_H