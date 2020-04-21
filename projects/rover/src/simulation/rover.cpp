#include "global.h"
#include "simulation/Rover.h"

Rover::Rover(InterThreadVariable<bool>* simulationRunning): running(simulationRunning){
    this->encountered->set(0);
    this->control.giveControlTo(ControlHierarchy::OVERSEER);
  };

void Rover::initialise() {
  this->overseer = std::thread(&Rover::oversee, this);
  this->multiple = std::thread(&Rover::checkForMultipleIssues, this);
  this->navigation = std::thread(&Rover::checkForNavigationIssues, this);
  this->wheelHeight = std::thread(&Rover::checkForWheelHeightIssues, this);
  this->wheelState = std::thread(&Rover::checkForWheelStateIssues, this);
  this->wheelMotion = std::thread(&Rover::checkForWheelMotionIssues, this);
}

void Rover::join() {
  this->overseer.join();
  this->groundControl.join();
  this->navigation.join();
  this->wheelHeight.join();
  this->wheelState.join();
  this->wheelMotion.join();
}
