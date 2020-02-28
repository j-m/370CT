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

    void forward(unsigned int metres);
    void backward(unsigned int metres);

    void pivot(signed int degrees);
    void pivotClockWise(unsigned int degrees);
    void privotCounterClockWise(unsigned int degrees);
};
