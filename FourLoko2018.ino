#include "FourLoko_Defines.h"
#include "FourLoko.h"


void setup() {
  Serial.begin(9600);
  initPins();
  initIrPwm();
//  startIrPwm();
}

void loop() {
  whereIsOpponent();
  delay(100);
}
