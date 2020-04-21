#include <chrono>
#include <random>

#include "global.h"
#include "simulation/Simulation.h"
#include "simulation/WheelState.h"

std::default_random_engine generator;

WheelState Simulation::getRandomWheelState() {
  std::uniform_int_distribution<int> hasIssue(0, 100);
  if (hasIssue(generator) > Global::Constants::PERCENTAGE_PROBABILITY_WHEEL_ISSUE) {
    return WheelState::OK;
  }
  std::uniform_int_distribution<int> problemChoice(1, WheelState::length);
  return static_cast<WheelState>(problemChoice(generator));
}

void Simulation::setWheelStates() {
  std::array<WheelState, Global::Constants::ROVER_NUMBER_OF_WHEELS> newStates;
  for(size_t index = 0; index < Global::Constants::ROVER_NUMBER_OF_WHEELS; index++) {
    newStates[index] = this->getRandomWheelState();
  }
  this->rover.states.set(newStates);
}

void Simulation::initialise() {
  while (Global::running.get() 
   && this->rover.encountered->get() < Global::Constants::PROBLEMS_PER_SIMULATION) {
    this->setWheelStates();
    this->encountered++;
  }  
}

void Simulation::join() {
  this->rover.join();
}
