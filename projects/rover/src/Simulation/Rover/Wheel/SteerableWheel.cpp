#include "./SteerableWheel.h"

SteerableWheel::SteerableWheel(): Wheel() { }

void SteerableWheel::rotateClockWise() {
  this->rotation = WheelRotation::CLOCKWISE;
}

void SteerableWheel::rotateCounterClockWise() {
  this->rotation = WheelRotation::COUNTER_CLOCKWISE;
}

void SteerableWheel::stopRotating() {
  this->rotation = WheelRotation::NONE;
}
