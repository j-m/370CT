#pragma once

#include "./Movement/Wheel.h"
#include "./Movement/SteerableWheel.h"
#include "./Sensors/Data.h"

enum class RoverMovement : int { 
  NONE,
  FORWARDS,
  BACKWARDS,
  STOP_MOVE,
  PREPARE_CW,
  PREPARE_CCW,
  RESET_ROTATION
};

class Rover {
  private:
    SteerableWheel wheelFrontLeft; 
    SteerableWheel wheelFrontRight;
    Wheel wheelMiddleLeft; 
    Wheel wheelMiddleRight; 
    SteerableWheel wheelBackLeft; 
    SteerableWheel wheelBackRight; 
    
    RoverMovement movement;
    
    Data previousData;
    Data data;
    
    void movementControl();
    void navigationControl();
    void sensor();
    void groundControl();
    void arbiter() ;
    void control();
    
    void forwards();
    void backwards();

    void prepareToPivotClockWise();
    void prepareToPivotCounterClockWise();
    
  public:
    Rover();
};
