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

void leftBrake() {
  digitalWrite(pwmL, HIGH);
  digitalWrite(stdbyL, HIGH);

  digitalWrite(in2L, HIGH); // raising both IN's high or setting PWM LOW turns on brakes
  digitalWrite(in1L, HIGH); // raising both IN's high or setting PWM LOW turns on brakes
}

void leftCoast() {
  digitalWrite(pwmL, HIGH);
  digitalWrite(stdbyL, HIGH);

  digitalWrite(in2L, LOW); // raising both IN's high or setting PWM LOW turns on brakes
  digitalWrite(in1L, LOW); // raising both IN's high or setting PWM LOW turns on
}

void rightBrake() {
  digitalWrite(pwmR, HIGH);
  digitalWrite(stdbyR, HIGH);

  digitalWrite(in2R, HIGH); // raising both IN's high or setting PWM LOW turns on brakes
  digitalWrite(in1R, HIGH); // raising both IN's high or setting PWM LOW turns on brakes
}

void rightCoast() {
  digitalWrite(pwmR, HIGH);
  digitalWrite(stdbyR, HIGH);

  digitalWrite(in2R, LOW);
  digitalWrite(in1R, LOW);
}

void motor(int motor, int velocity, int brakeState) {
  if (motor == left) {

    digitalWrite(stdbyL, HIGH); // todo: maybe this is always high too?
    digitalWrite(pwmL, HIGH); // todo: maybe this is always high?

    if (velocity > 0) {
      if (brakeState == coast) {
        digitalWrite(in1L, LOW);
        analogWrite(in2L, velocity);
      } else if (brakeState == brake) {
        digitalWrite(in1L, LOW);
        analogWrite(in2L, velocity);
      }
    } else {
      velocity = -velocity;
      if (brakeState == coast) {
        digitalWrite(in1L, HIGH);
        analogWrite(in2L, (255 - velocity));
      } else if (brakeState == brake) {
        digitalWrite(in1L, HIGH);
        analogWrite(in2L, (255 - velocity));
      }

    }
  } else if (motor == right) {

    digitalWrite(stdbyR, HIGH); // todo: maybe this is always high too?
    digitalWrite(pwmR, HIGH); // todo: maybe this is always high?

    if (velocity > 0) {
      if (brakeState == coast) {
        digitalWrite(in1R, HIGH);
        analogWrite(in2R, (255 - velocity));
      } else if (brakeState == brake) {
        digitalWrite(in1R, HIGH);
        analogWrite(in2R, (255 - velocity));
      }
    } else {
      velocity = -velocity;
      if (brakeState == coast) {
        digitalWrite(in1R, LOW);
        analogWrite(in2R, velocity);
      } else if (brakeState == brake) {
        digitalWrite(in1R, LOW);
        analogWrite(in2R, velocity);
      }
    }
  }

}





