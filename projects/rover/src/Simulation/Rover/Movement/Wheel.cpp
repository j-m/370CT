#include "./Wheel.h"

Wheel::Wheel() {
  this->power = WheelPower::NONE;
}

void Wheel::moveForwards() {
  this->power = WheelPower::POSITIVE;
}

void Wheel::moveBackwards() {
  this->power = WheelPower::NEGATIVE;
}

void Wheel::moveStop() {
  this->power = WheelPower::NONE;
}
