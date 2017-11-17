/**
   FourLoko.h
   Joshua Brown 2017

   helper functions for FourLoko, my minisumo bot
*/

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

void brake(int motor) {
  if (motor == left) {
    digitalWrite(in2L, HIGH);
    digitalWrite(in1L, HIGH);
  } else {
    digitalWrite(in2R, HIGH);
    digitalWrite(in1R, HIGH);
  }
}

void coast(int motor) {
  if (motor == left) {
    digitalWrite(in2L, LOW);
    digitalWrite(in1L, LOW);
  } else {
    digitalWrite(in2R, LOW);
    digitalWrite(in1R, LOW);
  }
}

void motor(int motor, int velocity, int brakeState) {
  if (motor == left) {

    if (velocity > 0) {
      if (brakeState == coasting) {
        digitalWrite(in1L, LOW);
        analogWrite(in2L, velocity);
      } else if (brakeState == braking) {
        digitalWrite(in1L, LOW);
        analogWrite(in2L, velocity);
      }
    } else {
      velocity = -velocity;
      if (brakeState == coasting) {
        digitalWrite(in1L, HIGH);
        analogWrite(in2L, (255 - velocity));
      } else if (brakeState == braking) {
        digitalWrite(in1L, HIGH);
        analogWrite(in2L, (255 - velocity));
      }

    }
  } else if (motor == right) {

    if (velocity > 0) {
      if (brakeState == coasting) {
        digitalWrite(in1R, HIGH);
        analogWrite(in2R, (255 - velocity));
      } else if (brakeState == braking) {
        digitalWrite(in1R, HIGH);
        analogWrite(in2R, (255 - velocity));
      }
    } else {
      velocity = -velocity;
      if (brakeState == coasting) {
        digitalWrite(in1R, LOW);
        analogWrite(in2R, velocity);
      } else if (brakeState == braking) {
        digitalWrite(in1R, LOW);
        analogWrite(in2R, velocity);
      }
    }
  }
}

void initPins() {
  pinMode(rightPx, INPUT);
  pinMode(in1L, OUTPUT);
  pinMode(in2L, OUTPUT);
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

  // ensure motor driver pins are LOW
  coast(left);
  coast(right);
}





