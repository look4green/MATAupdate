#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

bool encoderMoved();
int encoderDirection();
bool encoderClicked();
bool touchClicked();
void resetInactivityTimer();

#endif