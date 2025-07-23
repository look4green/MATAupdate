#include "Touchscreen.h"
#include <XPT2046_Touchscreen.h>

XPT2046_Touchscreen ts = XPT2046_Touchscreen(10, 255);  // CS, no IRQ

bool touchClicked() {
  return ts.touched();
}

void initTouchscreen() {
  ts.begin();
  ts.setRotation(1);
}