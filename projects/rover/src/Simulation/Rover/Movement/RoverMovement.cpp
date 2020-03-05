#include "../Rover.h"

void Rover::forwards() {
  this->wheelFrontLeft.forwards();
  this->wheelFrontRight.forwards();
  this->wheelMiddleLeft.forwards();
  this->wheelMiddleRight.forwards();
  this->wheelBackLeft.forwards();
  this->wheelBackRight.forwards();
}

void Rover::backwards() {
  this->wheelFrontLeft.backwards();
  this->wheelFrontRight.backwards();
  this->wheelMiddleLeft.backwards();
  this->wheelMiddleRight.backwards();
  this->wheelBackLeft.backwards();
  this->wheelBackRight.backwards();
}

void Rover::prepareToPivotClockWise() {
  this->wheelFrontLeft.rotateClockWise();
  this->wheelFrontRight.rotateClockWise();
  this->wheelBackLeft.rotateClockWise();
  this->wheelBackRight.rotateClockWise();
}

void Rover::prepareToPivotCounterClockWise() {
  this->wheelFrontLeft.rotateCounterClockWise();
  this->wheelFrontRight.rotateCounterClockWise();
  this->wheelBackLeft.rotateCounterClockWise();
  this->wheelBackRight.rotateCounterClockWise();
}
