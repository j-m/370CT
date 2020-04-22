#include <chrono>
#include <random>
#include <string>

#include "global.h"
#include "io.h"
#include "simulation/Simulation.h"
#include "simulation/WheelState.h"

std::default_random_engine generator(std::random_device{}());

WheelState Simulation::getRandomWheelState() {
  std::uniform_int_distribution<int> hasIssue(0, 100);
  if (hasIssue(generator) > Global::Constants::PERCENTAGE_PROBABILITY_WHEEL_ISSUE) {
    return WheelState::OK;
  }
  std::uniform_int_distribution<int> problemChoice(1, WheelState::length);
  return static_cast<WheelState>(problemChoice(generator));
}

void Simulation::setWheelStates() {
  std::vector<std::string> logMessages;
  std::array<WheelState, Global::Constants::ROVER_NUMBER_OF_WHEELS> newStates;
  for(size_t index = 0; index < Global::Constants::ROVER_NUMBER_OF_WHEELS; index++) {
    newStates[index] = this->getRandomWheelState();
    logMessages.push_back("WHEEL_" + std::to_string(index) + ": " + std::to_string(newStates[index]));
  }
  IO::Output::control.waitForControl(Control::PRODUCER);
  IO::Output::messageBuffer = logMessages;
  IO::Output::control.giveControlTo(Control::CONSUMER);
  this->rover.states.set(newStates);
}

Simulation::Simulation(SimulationFlag flag): flags(flag) {
  this->rover.initialise();
  this->thread = std::thread(&Simulation::loop, this);
}

void Simulation::loop() {
  while (Global::running && this->rover.running()) {
    this->rover.control.waitForControl(ControlHierarchy::ISSUER);
    this->setWheelStates();
    this->rover.control.giveControlTo(ControlHierarchy::ISSUER + 1);
  }  
  IO::Output::control.waitForControl(Control::PRODUCER);
  IO::Output::messageBuffer = {"Simulation complete"};
  IO::Output::control.giveControlTo(Control::CONSUMER);  
  this->join();
}

void Simulation::join() {
  this->rover.join();
}
