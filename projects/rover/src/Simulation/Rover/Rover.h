#pragma once

#include "./Movement/Wheel.h"
#include "./Movement/SteerableWheel.h"
#include "./Sensors/Data.h"

class Rover {
  private:
    SteerableWheel wheelFrontLeft; 
    SteerableWheel wheelFrontRight;
    Wheel wheelMiddleLeft; 
    Wheel wheelMiddleRight; 
    SteerableWheel wheelBackLeft; 
    SteerableWheel wheelBackRight; 

    Data data;
    
    void wheelControl();
    void movementControl();
    void navigationControl();
    void sensorControl();
    void groundControl();
    void arbiter();
    
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
