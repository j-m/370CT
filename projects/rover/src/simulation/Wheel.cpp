#include "global.h"
#include "simulation/Wheel.h"

void Wheel::initialise(InterThreadVariable<bool>* running, InterThreadVariable<int>* state) {
  this->running = running;
  this->state = state;
  this->thread = std::thread(&Wheel::loop, this);
}

void Wheel::join() {
  this->thread.join();
}

void Wheel::loop() {
  while (Global::running.get() && this->running->get()) {
     // random problem
     // log problem
  }
}
