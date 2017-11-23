/**
   FourLoko.h
   Joshua Brown 2017

   helper functions for FourLoko, my minisumo bot
*/

void initIrPwm() {
  TCCR1A = B01000000;
  TCCR1B = B00001001;
  OCR1A = 0;
}

void stopIrPwm() {
  OCR1A = 0;
}

void startIrPwm() {
  OCR1A = ocrConstant;
}

void printOpponentSensors(int *detectionArray) {
  for (int i = 0; i < 5; i++) {
    Serial.print(detectionArray[i]);
    Serial.print(", ");
  }
  Serial.println("");
}

void getOpponentSensors(int *detectionArray) {
  detectionArray[0] = digitalRead(fLefttPx);
  detectionArray[1] = digitalRead(leftPx);
  detectionArray[2] = digitalRead(ctrPx);
  detectionArray[3] = digitalRead(rightPx);
  detectionArray[4] = digitalRead(fRightPx);
}

int whereIsOpponent() {
  int result = 0; // which direction did is the opponent?
  int detectionArray[5]; // declare array of current opponennt sensor states
  
  getOpponentSensors(&detectionArray[0]);
  
  // todo: remove this and replace with actual logic to figure out where opponent is
  printOpponentSensors(detectionArray);
  
  return result;
}

void updateGyroDisplacement() {
  int delta = analogRead(gyroZ) - zeroRateGyroZ;
  if (abs(delta) > zThetaDeadband) {
    zThetaDisplacement = zThetaDisplacement + delta;
  }
}


void motorsDisable() {
  digitalWrite(motorStby, LOW);
}

void motorsEnable() {
  digitalWrite(motorStby, HIGH);
}

void brake(int motor) {
  if (motor == left) {
    digitalWrite(in2L, HIGH);
    digitalWrite(in1L, HIGH);
  } else {
    digitalWrite(in2R, HIGH);
    digitalWrite(in1R, HIGH);
  }
  motorsEnable();
}

void coast(int motor) {
  if (motor == left) {
    digitalWrite(in2L, LOW);
    digitalWrite(in1L, LOW);
  } else {
    digitalWrite(in2R, LOW);
    digitalWrite(in1R, LOW);
  }
  motorsEnable();
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
  motorsEnable();
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
  pinMode(motorStby, OUTPUT);

  motorsDisable();
  initIrPwm();

  // ensure motor driver pins are LOW
  coast(left);
  coast(right);
}

void motorModeDemo() {
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





