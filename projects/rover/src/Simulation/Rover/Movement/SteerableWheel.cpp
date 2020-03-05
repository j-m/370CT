#include "./SteerableWheel.h"

SteerableWheel::SteerableWheel(): Wheel() { }

void SteerableWheel::rotateClockWise() {
  this->rotation = WheelRotation::POSITIVE;
}

void SteerableWheel::rotateCounterClockWise() {
  this->rotation = WheelRotation::NEGATIVE;
}

void SteerableWheel::rotateCounterClockWise() {
  this->rotation = WheelRotation::NONE;
}
