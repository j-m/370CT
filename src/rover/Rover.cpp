#include "./Rover.h"
#include "./SteerableWheel.h"
#include "../io/Log.h"

unsigned int roverID = 0;
const float METRES_PER_WHEEL_REVOLUTION = 0.8;

Rover::Rover() {
  this->id = "Rover" + std::to_string(roverID++);
  this->wheelFrontLeft = new SteerableWheel(this->id  + " FrontLeftWheel");
  this->wheelFrontRight = new SteerableWheel(this->id  + "FrontRightWheel");
  this->wheelMiddleLeft = new Wheel(this->id  + "MiddleLeftWheel");
  this->wheelMiddleRight = new Wheel(this->id  + "MiddleRightWheel");
  this->wheelBackLeft = new SteerableWheel(this->id  + "BackLeftWheel");
  this->wheelBackRight = new SteerableWheel(this->id  + "BackRightWheel");
  this->log("Online");
}

void Rover::log(std::string message) {
  Log::message(this->id, message);
}

void Rover::forward(unsigned int metres) {
  const double revolutions = metres / METRES_PER_WHEEL_REVOLUTION;
  this->wheelFrontLeft->revolve(revolutions);
  this->wheelFrontRight->revolve(revolutions);
  this->wheelMiddleLeft->revolve(revolutions);
  this->wheelMiddleRight->revolve(revolutions);
  this->wheelBackLeft->revolve(revolutions);
  this->wheelBackRight->revolve(revolutions);
}
void Rover::backward(unsigned int metres) {
  this->wheelFrontLeft
  this->wheelFrontRight
  this->wheelMiddleLeft
  this->wheelMiddleRight
  this->wheelBackLeft
  this->wheelBackRight
}

void Rover::pivot(signed int degrees) {
  this->wheelFrontLeft
  this->wheelFrontRight
  this->wheelMiddleLeft
  this->wheelMiddleRight
  this->wheelBackLeft
  this->wheelBackRight
}
void Rover::pivotClockWise(unsigned int degrees) {
  this->wheelFrontLeft
  this->wheelFrontRight
  this->wheelMiddleLeft
  this->wheelMiddleRight
  this->wheelBackLeft
  this->wheelBackRight
}
void Rover::privotCounterClockWise(unsigned int degrees) {
  this->wheelFrontLeft
  this->wheelFrontRight
  this->wheelMiddleLeft
  this->wheelMiddleRight
  this->wheelBackLeft
  this->wheelBackRight
}
