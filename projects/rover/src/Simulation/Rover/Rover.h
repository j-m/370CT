#pragma once

#include "./Wheel.h"
#include "./SteerableWheel.h"

#include <string>

class Rover {
  private:
    SteerableWheel wheelFrontLeft; 
    SteerableWheel wheelFrontRight;
    Wheel wheelMiddleLeft; 
    Wheel wheelMiddleRight; 
    SteerableWheel wheelBackLeft; 
    SteerableWheel wheelBackRight; 
  public:
    Rover();

    void forward();
    void backward();

    void resetSteerableWheels();
    void setSteerableWheelsToPivotClockWise();
    void setSteerableWheelsToPivotCounterClockWise();
};
