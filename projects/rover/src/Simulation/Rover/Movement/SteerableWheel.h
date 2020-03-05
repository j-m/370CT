#pragma once

#include "./Wheel.h"

enum class WheelRotation : int { 
  NONE = 0,
  CLOCKWISE = 1,
  COUNTER_CLOCKWISE = -1
};

class SteerableWheel : public Wheel {
  private:
    WheelRotation rotation;
    
  public: 
    SteerableWheel();

    void rotateClockWise();
    void rotateCounterClockWise();
    void rotateStop();
};
