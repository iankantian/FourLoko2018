/**
 * FourLoko.h
 * Joshua Brown 2017
 * 
 * helper functions for FourLoko, my minisumo bot
 */

void initPins() {
  pinMode(rightPx, INPUT);
  pinMode(in1R, OUTPUT);
  pinMode(pwmR, INPUT); // TODO: SWITCH TO OUTPUT FOR USING MOTORS
  pinMode(pwmL, INPUT); // TODO: SWITCH TO OUTPUT FOR USING MOTORS
  pinMode(in2L, OUTPUT);
  pinMode(in1L, OUTPUT);
  pinMode(stdbyL, OUTPUT);
  pinMode(irPwm, OUTPUT);
  pinMode(ctrPx, INPUT);
  pinMode(usrBtn1, INPUT);
  pinMode(usrBtn2, INPUT);
  pinMode(fLefttPx, INPUT);
  pinMode(leftPx, INPUT);
  pinMode(in2R, OUTPUT);
  pinMode(vSense, INPUT);
  pinMode(edgeLeft, INPUT);
  pinMode(edgeRight, INPUT);
  pinMode(fRightPx, INPUT);
  pinMode(gyroZ, INPUT);
  pinMode(stdbyR, OUTPUT);
}

void initIrPwm() {
  TCCR1A = B01000000;
  TCCR1B = B00001001;
}

void stopIrPwm() {
  OCR1A = 0;
}

void startIrPwm() {
  OCR1A = ocrConstant;
}

void printOpponentSensors() {
  Serial.print("Opponent Sensors, LL, L, C, R, RR: ");
  Serial.print(digitalRead(fLefttPx));
  Serial.print(digitalRead(leftPx));
  Serial.print(digitalRead(ctrPx));
  Serial.print(digitalRead(rightPx));
  Serial.println(digitalRead(fRightPx));
}

void updateGyroDisplacement() {
  int delta = analogRead(gyroZ) - zeroRateGyroZ;
  if (abs(delta) > zThetaDeadband) {
      zThetaDisplacement = zThetaDisplacement + delta;
  }
}


