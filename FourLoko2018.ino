#include "FourLoko.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initPins();
  startIrPwm(IR_CLOCK_RATE);
//  stopIrPwm();
}

void loop() {
  int delta = analogRead(gyroZ) - zeroRateGyroZ;
  if (abs(delta) > zThetaDeadband) {
      zThetaDisplacement = zThetaDisplacement + delta;
  } 
  
  Serial.print("zThetaDisplacement is: ");
  Serial.println(zThetaDisplacement);
  delay(20);
}
