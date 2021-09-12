#include "GoBLE.h"

// RM_SPD Pin 5 (E1) Right Motor Speed Control
// LM_SPD Pin 6 (E2) Left Motor Speed Control
// RM_DIR Pin 4 (M1) Right Motor Direction Control
// LM_DIR Pin 7 (M2) Left Motor Direction Control
#define LM_DIR 7
#define LM_SPD 6
#define RM_DIR 4
#define RM_SPD 5
#define MAX_SPEED 255
#define MID_SPEED 128
#define MIN_SPEED 0
#define DIR_FWD LOW
#define DIR_REV HIGH

int joystickX, joystickY;

void turtleStop()
{
  // set both motors to minimum speed (stopped)
  digitalWrite(LM_SPD, MIN_SPEED);
  digitalWrite(RM_SPD, MIN_SPEED);
}

void turtleForward(int speed)
{
  // set both motors to run forward at provided speed
  analogWrite(LM_SPD, speed);
  digitalWrite(LM_DIR, DIR_FWD);
  analogWrite(RM_SPD, speed);
  digitalWrite(RM_DIR, DIR_FWD);
}

void turtleReverse(int speed)
{
  // set both motors to run reverse at provided speed
  analogWrite(LM_SPD, speed);
  digitalWrite(LM_DIR, DIR_REV);
  analogWrite(RM_SPD, speed);
  digitalWrite(RM_DIR, DIR_REV);
}

void turtleLeft(int speed)
{
  // turn left by setting left motor to reverse and right motor forward
  // and running them at the provided speed
  analogWrite(LM_SPD, speed);
  digitalWrite(LM_DIR, DIR_REV);
  analogWrite(RM_SPD, speed);
  digitalWrite(RM_DIR, DIR_FWD);
}

void turtleRight(int speed)
{
  // turn right by setting left motor to forward and right motor to reverse
  // and running them at the provided speed
  analogWrite(LM_SPD, speed);
  digitalWrite(LM_DIR, DIR_FWD);
  analogWrite(RM_SPD, speed);
  digitalWrite(RM_DIR, DIR_REV);
}

void setup()
{
  pinMode(LM_SPD, OUTPUT);
  pinMode(RM_SPD, OUTPUT);
  pinMode(LM_DIR, OUTPUT);
  pinMode(RM_DIR, OUTPUT);

  Goble.begin();
  Serial.begin(115200);
  turtleStop();
}

void loop()
{
  // handle bluetooth controller input
  if (Goble.available()) {
    // joystick values are 128 when idle, and go from 1 to 255
    // where 1 is far bottom for joystickX, and 255 is far top
    // and 1 is far left for joystickY, and 255 is far right
    joystickX = Goble.readJoystickX();
    joystickY = Goble.readJoystickY();

    if (joystickX > 213) {
      turtleForward(MAX_SPEED);
    } else if (joystickX < 43) {
      turtleReverse(MAX_SPEED);
    } else if (joystickY < 43) {
      turtleLeft(MID_SPEED);
    } else if (joystickY > 213) {
      turtleRight(MID_SPEED);
    } else {
      turtleStop();
    }
  }
}
