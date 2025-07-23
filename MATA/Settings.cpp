#include "Settings.h"
#include "Display.h"
#include "InputHandler.h"
#include "ThemeManager.h"

int settingIndex = 0;           // Define once here
const int settingCount = 2;

void updateSettingsPanel() {
  drawTitleBar("Settings");

  if (encoderMoved()) {
    if (encoderDirection() > 0) settingIndex = (settingIndex + 1) % settingCount;
    else settingIndex = (settingIndex - 1 + settingCount) % settingCount;
    resetInactivityTimer();
  }

  if (encoderClicked() || touchClicked()) {
    resetInactivityTimer();
    String msg;

    switch (settingIndex) {
      case 0:
        msg = "Theme: DarkMode";
        break;
      case 1:
        msg = "Profile: DefaultProfile";
        break;
    }

    drawStatus(msg.c_str());
  }

  drawStatus(settingIndex == 0 ? "Select Theme" : "Select Profile");
}