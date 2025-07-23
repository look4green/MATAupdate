#include "InputHandler.h"
#include <Encoder.h>

// Replace with your actual encoder pins
Encoder encoder(2, 3);  // CLK, DT
const int encoderButtonPin = 4;  // Push button pin

long lastPosition = -999;

bool encoderMoved() {
  long newPosition = encoder.read();
  bool moved = (newPosition != lastPosition);
  lastPosition = newPosition;
  return moved;
}

int encoderDirection() {
  long newPosition = encoder.read();
  int direction = (newPosition > lastPosition) ? 1 : (newPosition < lastPosition) ? -1 : 0;
  lastPosition = newPosition;
  return direction;
}

bool encoderClicked() {
  return digitalRead(encoderButtonPin) == LOW;  // Assuming active LOW
}

void resetInactivityTimer() {
  // Add your screen timeout or sleep logic here
}