#include "FourLoko_Defines.h"
#include "FourLoko.h"


void setup() {
  Serial.begin(115200);
  initPins();
  startIrPwm();
}

int onLoops = 100;
int offMs = 40;
int currentLoop = 0;

void loop() {
  currentLoop++;
  if (currentLoop > onLoops) { // cooldown the IR sensors, they get saturated and need to be left off.
    currentLoop = 0;
    stopIrPwm();
    delay(offMs);
    startIrPwm();
  }
  whereIsOpponent();
}
