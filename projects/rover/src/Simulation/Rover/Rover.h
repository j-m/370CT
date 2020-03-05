#pragma once

#include "./Movement/Wheel.h"
#include "./Movement/SteerableWheel.h"

class Rover {
  private:
    SteerableWheel wheelFrontLeft; 
    SteerableWheel wheelFrontRight;
    Wheel wheelMiddleLeft; 
    Wheel wheelMiddleRight; 
    SteerableWheel wheelBackLeft; 
    SteerableWheel wheelBackRight; 
    
    void movementControl();
    void navigationControl();
    void sensor();
    void groundControl();
    void arbiter() ;
    void control();
    
  public:
    Rover();
  
    void forward();
    void backward();

    void resetSteerableWheels();
    void setSteerableWheelsToPivotClockWise();
    void setSteerableWheelsToPivotCounterClockWise();
};
