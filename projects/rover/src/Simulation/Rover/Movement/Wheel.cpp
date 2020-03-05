#include "./Wheel.h"

Wheel::Wheel() {
  this->power = WheelPower::NONE;
}

void Wheel::forwards() {
  this->power = WheelPower::POSITIVE;
}

void Wheel::backwards() {
  this->power = WheelPower::NEGATIVE;
}

void Wheel::stopMoving() {
  this->power = WheelPower::NONE;
}
