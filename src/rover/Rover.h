#pragma once

#include "./Wheel.h"
#include "./SteerableWheel.h"

#include <string>

class Rover {
  private:
    std::string id;
    
    SteerableWheel* wheelFrontLeft; 
    SteerableWheel* wheelFrontRight;
    Wheel* wheelMiddleLeft; 
    Wheel* wheelMiddleRight; 
    SteerableWheel* wheelBackLeft; 
    SteerableWheel* wheelBackRight; 
  
    void log(std::string message);
  
  public:
    Rover();
};
