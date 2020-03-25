#include "../Rover.h"
#include "./MovementCommand.h"

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

void Rover::pivotClockWise() {
  this->wheelFrontLeft.forwards();
  this->wheelFrontRight.forwards();
  this->wheelMiddleLeft.forwards();
  this->wheelMiddleRight.backwards();
  this->wheelBackLeft.forwards();
  this->wheelBackRight.forwards();
}

void Rover::pivotCounterClockWise() {
  this->wheelFrontLeft.forwards();
  this->wheelFrontRight.forwards();
  this->wheelMiddleLeft.backwards();
  this->wheelMiddleRight.forwards();
  this->wheelBackLeft.forwards();
  this->wheelBackRight.forwards();
}

void Rover::resetWheelAngles() {
  this->wheelFrontLeft.rotateCounterClockWise();
  this->wheelFrontRight.rotateCounterClockWise();
  this->wheelBackLeft.rotateCounterClockWise();
  this->wheelBackRight.rotateCounterClockWise();
}

void Rover::movementControl() {  
  while (true) {
    switch (this->movement) { 
      case MovementCommand::NONE:
        this->stop();
        break;
      case MovementCommand::FORWARDS:
        this->forwards();
        break;
      case MovementCommand::BACKWARDS:
        this->backwards();
        break;
      case MovementCommand::PREPARE_CLOCK_WISE:
        this->prepareToPivotClockWise();
        break;  
      case MovementCommand::PREPARE_COUNTER_CLOCK_WISE:
        this->prepareToPivotCounterClockWise();
        break;
      case MovementCommand::PIVOT_CLOCK_WISE:
        this->pivotClockWise();
        break;
      case MovementCommand::PIVOT_COUNTER_CLOCK_WISE:
        this->pivotCounterClockWise();
        break;
      case MovementCommand::RESET_WHEEL_ANGLES:
        this->resetWheelAngles();
        break;
      default:
        break;
    }
  }
}
