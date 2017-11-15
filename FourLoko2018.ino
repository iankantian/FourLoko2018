#include "FourLoko_Defines.h"
#include "FourLoko.h"


void setup() {
  Serial.begin(9600);
  initPins();
//  initIrPwm();
//  startIrPwm();
}

void loop() {
  newMotor(right, -30, coast);
  Serial.println("coasting backward");
  delay(300);
  newRightCoast();
  delay(4000);
  newMotor(right, -30, brake);
  Serial.println("braking backward");
  delay(300);
  newRightBrake();
  delay(4000);
  newMotor(right, 30, coast);
  Serial.println("coasting forward");
  delay(300);
  newRightCoast();
  delay(4000);
  newMotor(right, 30, brake);
  Serial.println("braking forward");
  delay(300);
  newRightBrake();
  delay(4000);
}
