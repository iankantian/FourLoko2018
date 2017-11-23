/**
 * FourLoko_Defines.h
 * Joshua Brown 2017
 * 
 * Pin definitions and constants for FourLoko, my minisumo bot
 */
 
// Px is proximity sensor
// Lx is line sensor

#define rightPx A3    // IR Receiver for opponent detection, this one is right of center
#define in1R    12    // one of the two directional inputs per h-bridge channel, the other being in2R (pin 13)
#define in2L    6     // see truth table for how these go, consider re-wiring to allow coasting style PWM, it's braking style now...
#define in1L    5     // https://toshiba.semicon-storage.com/info/docget.jsp?did=10660&prodName=TB6612FNG
#define irPwm   9     // ~38 kHz square wave at 50% duty cycle
#define ctrPx   1     // center IR receiver
#define usrBtn1 3     
#define usrBtn2 2
#define fLefttPx 4    // far left of center opponent IR detector
#define leftPx   0    // left of center opponent IR detector
#define motorStby 7
#define in2R      13
#define vSense    A0  // battery sensing, on 3 cell lipo / 3: 10% is 3.7v reads about 435, 100% 4.2v reads 495
#define edgeLeft  A1  // for detecting the edge of the sumo dohyo ~43 edge, 1017 dohyo
#define edgeRight A2  // ~ 1012 black dohyo to 38 white edge
#define fRightPx  A4  // far right of center IR detector
#define gyroZ     99  // Z axis gyro! an analog sensor, might use it for directional integration? no rate is 293, reduces for CC rotation integrating delta at 50z gives units of about 2200 per rotation

#define IR_CLOCK_RATE    36000L
#define ocrConstant     (F_CPU/(IR_CLOCK_RATE*2L)-1)

#define zeroRateGyroZ    293 // todo: do some automatic calibration instead
int zThetaDisplacement = 0;
#define zThetaDeadband   1

#define none      0
#define farLeft   1
#define left      2
#define center    3
#define right     4
#define farRight  5
#define coasting false
#define braking true
#define detection  0
#define noDetection 1


