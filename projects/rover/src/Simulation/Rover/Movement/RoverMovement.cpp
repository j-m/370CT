#include "../Rover.h"

void Rover::revolveAllWheels(const double revolutions) {
  this->wheelFrontLeft->revolve(revolutions);
  this->wheelFrontRight->revolve(revolutions);
  this->wheelMiddleLeft->revolve(revolutions);
  this->wheelMiddleRight->revolve(revolutions);
  this->wheelBackLeft->revolve(revolutions);
  this->wheelBackRight->revolve(revolutions);
}

void Rover::resetSteerableWheels() {
  this->wheelFrontLeft->rotateToAngle(0);
  this->wheelFrontRight->rotateToAngle(0);
  this->wheelBackLeft->rotateToAngle(0);
  this->wheelBackRight->rotateToAngle(0);
}

void Rover::forward() {
  const double revolutions = metres / METRES_PER_WHEEL_REVOLUTION;
  this->revolveAllWheels(revolutions);
}

void Rover::backward() {
  const double revolutions = metres / METRES_PER_WHEEL_REVOLUTION;
  this->revolveAllWheels(-revolutions);
}


void Rover::pivotClockWise(const double degrees) {
  const double revolutions = degrees / METRES_PER_WHEEL_REVOLUTION;
  this->wheelFrontLeft->rotateToAngle(45);
  this->wheelFrontRight->rotateToAngle(135);
  this->wheelBackLeft->rotateToAngle(315);
  this->wheelBackRight->rotateToAngle(225);
  
  this->revolveAllWheels(revolutions);
  this->resetSteerableWheels();
}

void Rover::pivotCounterClockWise(const double degrees) {
  const double revolutions = degrees / METRES_PER_WHEEL_REVOLUTION;
  this->wheelFrontLeft->rotateToAngle(225);
  this->wheelFrontRight->rotateToAngle(315);
  this->wheelBackLeft->rotateToAngle(135);
  this->wheelBackRight->rotateToAngle(45);
  
  this->revolveAllWheels(revolutions);
  this->resetSteerableWheels();
}
