#pragma once

#include "./Movement/Wheel.h"
#include "./Movement/SteerableWheel.h"
#include "./Control/MovementCommand.h"
#include "./Control/WheelCommandSet.h"

class Rover {
  private:
    SteerableWheel wheelFrontLeft; 
    SteerableWheel wheelFrontRight;
    Wheel wheelMiddleLeft; 
    Wheel wheelMiddleRight; 
    SteerableWheel wheelBackLeft; 
    SteerableWheel wheelBackRight; 
    
    WheelCommandSet wheelCommandSet;
    MovementCommand movementCommand;
    void wheelControl();
    void movementControl();
    
    void stop();
    void forwards();
    void backwards();
    void prepareToPivotClockWise();
    void prepareToPivotCounterClockWise();
    void pivotClockWise();
    void pivotCounterClockWise();
    void resetWheelAngles();
    
  public:
    Rover();
};
