#include "global.h"
#include "simulation/Rover.h"

Rover::Rover() {
  this->encountered = 0;
  this->running.set(true);
}

void Rover::initialise() {
  this->arbiter = std::thread(&Rover::arbitrate, this);
}

void Rover::join() {
  this->arbiter.join();
}

void Rover::arbitrate() {
  while (Global::running.get() && this->running->get()) {
    for(size_t index = 0; index < Global::Constants::ROVER_NUMBER_OF_WHEELS; index++) {
      this->states[index]);    
    }
    
    this->encountered++;
    //each solution passes control to next if unresolved
    //log chosen solution
    
    if (this->encountered >= Global::Constants::PROBLEMS_PER_SIMULATION) {
      this->running.set(false);
    }
  }
}
