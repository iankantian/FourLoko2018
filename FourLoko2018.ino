#include "FourLoko_Defines.h"
#include "FourLoko.h"


void setup() {
  Serial.begin(9600);
  initPins();
  initIrPwm();
  startIrPwm();
}

void loop() {
//  motor(left, 80);
//  motor(right, 80);
//  delay(100);
//  leftBrake();
//  rightBrake();
//  delay(4000);
}
