#include "global.h"
#include "simulation/Rover.h"

Rover::Rover() {
  this->encountered = 0;
  this->finished = false;
  this->command = RoverCommands::NONE;
  this->control.giveControlTo(ControlHierarchy::ISSUER);
}

void Rover::initialise() {
  this->resolver = std::thread(&Rover::resolve, this);
  this->numberIssues = std::thread(&Rover::checkNumberOfIssues, this);
  this->navigation = std::thread(&Rover::checkForNavigationIssues, this);
  this->wheelHeight = std::thread(&Rover::checkForWheelHeightIssues, this);
  this->wheelState = std::thread(&Rover::checkForWheelStateIssues, this);
  this->wheelMotion = std::thread(&Rover::checkForWheelMotionIssues, this);
}

void Rover::join() {
  this->resolver.join();
  this->numberIssues.join();
  this->navigation.join();
  this->wheelHeight.join();
  this->wheelState.join();
  this->wheelMotion.join();
}
