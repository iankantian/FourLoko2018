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
  int restDuration = 2000;
  
  motor(left, -testSpeed, coasting);
  Serial.println("left coasting backward");
  delay(driveDuration);
  coast(left);
  delay(restDuration);
  motor(left, -testSpeed, braking);
  Serial.println("left braking backward");
  delay(driveDuration);
  brake(left);
  delay(restDuration);
  motor(left, testSpeed, coasting);
  Serial.println("left coasting forward");
  delay(driveDuration);
  coast(left);
  delay(restDuration);
  motor(left, testSpeed, braking);
  Serial.println("left braking forward");
  delay(driveDuration);
  brake(left);
  delay(restDuration);

  motor(right, -testSpeed, coasting);
  Serial.println("right coasting backward");
  delay(driveDuration);
  coast(right);
  delay(restDuration);
  motor(right, -testSpeed, braking);
  Serial.println("right braking backward");
  delay(driveDuration);
  brake(right);
  delay(restDuration);
  motor(right, testSpeed, coasting);
  Serial.println("right coasting forward");
  delay(driveDuration);
  coast(right);
  delay(restDuration);
  motor(right, testSpeed, braking);
  Serial.println("right braking forward");
  delay(driveDuration);
  brake(right);
  delay(restDuration);
}
