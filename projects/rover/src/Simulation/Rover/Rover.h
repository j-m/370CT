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
    
    void movementControl();
    void navigationControl();
    void sensor();
    void groundControl();
    void arbiter() ;
    void control();
    
  public:
    Rover();
  
    void forwards();
    void backwards();

    void prepareToPivotClockWise();
    void prepareToPivotCounterClockWise();
};
