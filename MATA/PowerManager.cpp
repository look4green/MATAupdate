#include "PowerManager.h"
#include "Display.h"
#include "InputHandler.h"

void updatePowerManager() {
  drawTitleBar("Power Manager");
  drawStatus("Monitoring power...");

  if (encoderMoved() || encoderClicked() || touchClicked()) {
    resetInactivityTimer();
    drawStatus("User interaction detected");
  }

  // Future: Add battery status, sleep mode, etc.
}