#include "FourLoko_Defines.h"
#include "FourLoko.h"


void setup() {
  Serial.begin(9600);
  initPins();
//  initIrPwm();
//  startIrPwm();
}

void loop() {
  int testSpeed = 30;
  int driveDuration = 300;
  int restDuration = 4000;
  
  motor(left, -testSpeed, coast);
  Serial.println("left coasting backward");
  delay(driveDuration);
  leftCoast();
  delay(restDuration);
  motor(left, -testSpeed, brake);
  Serial.println("left braking backward");
  delay(driveDuration);
  leftBrake();
  delay(restDuration);
  motor(left, testSpeed, coast);
  Serial.println("left coasting forward");
  delay(driveDuration);
  leftCoast();
  delay(restDuration);
  motor(left, testSpeed, brake);
  Serial.println("left braking forward");
  delay(driveDuration);
  leftBrake();
  delay(restDuration);

  motor(right, -testSpeed, coast);
  Serial.println("right coasting backward");
  delay(driveDuration);
  rightCoast();
  delay(restDuration);
  motor(right, -testSpeed, brake);
  Serial.println("right braking backward");
  delay(driveDuration);
  rightBrake();
  delay(restDuration);
  motor(right, testSpeed, coast);
  Serial.println("right coasting forward");
  delay(driveDuration);
  rightCoast();
  delay(restDuration);
  motor(right, testSpeed, brake);
  Serial.println("right braking forward");
  delay(driveDuration);
  rightBrake();
  delay(restDuration);
}
