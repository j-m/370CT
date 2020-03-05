#pragma once

#include <string>

enum WheelPower { 
  NONE = 0,
  POSITIVE = 1,
  NEGATIVE = -1
};

class Wheel {
  protected:
    WheelPower power;
    unsigned int odometer;

  public:
    Wheel();

    void forwards();
    void backwards();
    void stop();
};
