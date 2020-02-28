#pragma once

#include "./Wheel.h"

#include <string>

class SteerableWheel : public Wheel {
  private:
    unsigned int angle;

  public: 
    SteerableWheel(std::string wheelID);
};
