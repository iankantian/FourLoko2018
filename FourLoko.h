// Px is proximity sensor
// Lx is line sensor

// upside down pinout (under the breadboard)
#define rightPx 12    // IR Receiver for opponent detection, this one is right of center
#define in1R    11    // one of the two directional inputs per h-bridge channel, the other being in2R (pin 13)
#define pwmR    10    // speed controls, would really like to get a PWM channel for each motor, (4)
#define pwmL    9
#define in2L    8     // see truth table for how these go, consider re-wiring to allow coasting style PWM, it's braking style now...
#define in1L    7     // https://toshiba.semicon-storage.com/info/docget.jsp?did=10660&prodName=TB6612FNG
#define stdbyL  6     // pull to ground to enable H-Bridge channel, could probably have all 4 drivers on same...
#define irPwm   5     // ~38 kHz square wave at 50% duty cycle
#define ctrPx   4     // center IR receiver
#define usrBtn1 3     
#define usrBtn2 2
// gnd
// rst
#define fLefttPx 0    // far left of center opponent IR detector
#define leftPx   1    // left of center opponent IR detector
// rx_ss
// MOSI

// other side of micro:
#define in2R  13
// 3.3V
// AREF
#define vSense A0     // battery sensing, on 3 cell lipo / 3: 10% is 3.7v reads about 435, 100% 4.2v reads 495
#define lineLeft A1   // for detecting the edge of the sumo dohyo
#define lineRight A2
#define fRightPx A3   // far right of center IR detector
#define gyroZ A4        // Z axis gyro! an analog sensor, might use it for directional integration?
#define stdbyR A5       // for disabling the H-Bridge
// no
// no
// +5
// rst
// gnd
// Vin
// MISO
// SK

void initPins() {
  pinMode(rightPx, INPUT);
  pinMode(in1R, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(pwmL, OUTPUT);
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
  pinMode(lineLeft, INPUT);
  pinMode(lineRight, INPUT);
  pinMode(fRightPx, INPUT);
  pinMode(gyroZ, INPUT);
  pinMode(stdbyR, OUTPUT);
}


