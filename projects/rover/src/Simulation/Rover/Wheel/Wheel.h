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

    void forwards();
    void backwards();
    void stopMoving();
};
