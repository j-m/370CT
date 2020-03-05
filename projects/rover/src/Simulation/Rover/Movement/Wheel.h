#pragma once

enum class WheelPower : int { 
  NONE = 0,
  POSITIVE = 1,
  NEGATIVE = -1
};

class Wheel {
  protected:
    WheelPower power;

  public:
    Wheel();

    void moveForwards();
    void moveBackwards();
    void moveStop();
};
