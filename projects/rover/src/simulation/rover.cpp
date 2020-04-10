#include "global.h"
#include "simulation/Rover.h"

Rover::Rover() {
  this->encountered = 0;
  this->running.set(true);
}

void Rover::initialise() {
  for(size_t index = 0; index < Global::Constants::ROVER_NUMBER_OF_WHEELS; index++) {
    this->wheels[index].initialise(&this->running, &this->states[index]);
  }
  std::thread(&Rover::arbitrate, this);
}

void Rover::join() {
  for(size_t index = 0; index < Global::Constants::ROVER_NUMBER_OF_WHEELS; index++) {
    this->wheels[index].join();
  }
}

void Rover::arbitrate() {
  while (Global::running.get() && this->running.get()) {
    for(size_t index = 0; index < Global::Constants::ROVER_NUMBER_OF_WHEELS; index++) {
      //this.arbiter(this->wheels[index]->state);    
    }
    
    this->encountered++;
    //each solution passes control to next if unresolved
    //log chosen solution
    
    if (this->encountered >= Global::Constants::PROBLEMS_PER_SIMULATION) {
      this->running.set(false);
    }
  }
}
