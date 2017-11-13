/**
   FourLoko.h
   Joshua Brown 2017

   helper functions for FourLoko, my minisumo bot
*/

void initPins() {
  pinMode(rightPx, INPUT);
  pinMode(pwmR, OUTPUT); // TODO: SWITCH TO OUTPUT FOR USING MOTORS
  pinMode(pwmL, OUTPUT); // TODO: SWITCH TO OUTPUT FOR USING MOTORS
  pinMode(in1L, OUTPUT);
  pinMode(in2L, OUTPUT);
  pinMode(stdbyL, OUTPUT);
  pinMode(stdbyR, OUTPUT);
  pinMode(in1R, OUTPUT);
  pinMode(in2R, OUTPUT);
  pinMode(irPwm, OUTPUT);
  pinMode(ctrPx, INPUT);
  pinMode(usrBtn1, INPUT);
  pinMode(usrBtn2, INPUT);
  pinMode(fLefttPx, INPUT);
  pinMode(leftPx, INPUT);
  pinMode(vSense, INPUT);
  pinMode(edgeLeft, INPUT);
  pinMode(edgeRight, INPUT);
  pinMode(fRightPx, INPUT);
  pinMode(gyroZ, INPUT);
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

void rightCoast() {
  digitalWrite(stdbyR, LOW);
  digitalWrite(in2R, LOW);
  digitalWrite(in1R, LOW);
}

void rightBrake() {
  digitalWrite(stdbyR, HIGH);
  digitalWrite(in2R, HIGH); // raising both IN's high or setting PWM LOW turns on brakes
  digitalWrite(in1R, HIGH); // raising both IN's high or setting PWM LOW turns on brakes
}

void rightRotate(int velocity) {
  if (velocity > 0) {
    digitalWrite(in1R, HIGH);
    digitalWrite(in2R, LOW);
  } else {
    digitalWrite(in1R, LOW);
    digitalWrite(in2R, HIGH);
    velocity = -velocity;
  }

  digitalWrite(pwmR, HIGH);
  analogWrite(stdbyR, velocity);
}

void rightRotate(int velocity, bool braked) {
  if (velocity > 0) {
    digitalWrite(in1R, HIGH);
    digitalWrite(in2R, LOW);
  } else {
    digitalWrite(in1R, LOW);
    digitalWrite(in2R, HIGH);
    velocity = -velocity;
  }

  if (braked) {
    digitalWrite(stdbyR, HIGH);
    analogWrite(pwmR, velocity);
  } else {
    digitalWrite(pwmR, HIGH);
    analogWrite(stdbyR, velocity);
  }
}


