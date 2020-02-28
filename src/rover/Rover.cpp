#include "./Rover.h"
#include "./SteerableWheel.h"
#include "../io/Log.h"

unsigned int roverID = 0;

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
