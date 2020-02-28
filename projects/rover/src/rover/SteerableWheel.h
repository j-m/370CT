#pragma once

#include "./Wheel.h"

#include <string>

class SteerableWheel : public Wheel {
  private:
    double angle;

    void rotateClockWise(const double degrees);
    void rotateCounterClockWise(const double degrees);
  public: 
    SteerableWheel(std::string wheelID);

    void rotateToAngle(const double angle);
};
