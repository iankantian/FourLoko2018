#include "FourLoko_Defines.h"
#include "FourLoko.h"


void setup() {
  Serial.begin(9600);
  initPins();
//  initIrPwm();
//  startIrPwm();
}

void loop() {
  newMotor(left, -30, coast);
  delay(400);
  newLeftCoast();
  delay(4000);
  newMotor(left, -30, brake);
  delay(400);
  newLeftBrake();
  delay(4000);

  newMotor(right, 30, coast);
  delay(400);
  newRightCoast();
  delay(4000);
  newMotor(right, 30, brake);
  delay(400);
  newRightBrake();
  delay(4000);
}
