#include "FourLoko_Defines.h"
#include "FourLoko.h"

const int arrayHistoryLength = 100;
int arrayHistory[arrayHistoryLength];
int loopCount = 0;
const int loopMax = 100;
int detectTotal = 0;

void setup() {
  Serial.begin(9600);
  initPins();
  for (int i = 0; i < arrayHistoryLength; i++) { // initialize the array
    arrayHistory[i] = 0;
  }
  startIrPwm();
}




void loop() {
  int l = arrayHistoryLength - 1;
  for (int i = 0; i < l; i++) { // shift those values!
    arrayHistory[i] = arrayHistory[i + 1];
  }



  int res = digitalRead(8) == 1 ? 0 : 1;
  arrayHistory[l] = res;



  loopCount++;
  if (loopCount > loopMax) {
    loopCount = 0;

    detectTotal = 0;
    for (int i = 0; i < arrayHistoryLength; i++) { // total the values
      detectTotal += arrayHistory[i];
    }
    Serial.println(detectTotal);
  }
}
