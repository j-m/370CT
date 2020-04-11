#include <chrono>
#include <random>

#include "global.h"
#include "simulation/Wheel.h"
#include "simulation/WheelState.h"

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
    std::default_random_engine generator;
    std::uniform_int_distribution<int> issueProbability(0, 100);
    if (issueProbability(generator) == 1) {

      std::uniform_int_distribution<int> problemChoice(1, WheelState::length);
      this->state->set(static_cast<WheelState>(problemChoice(generator)));
      
      // log problem
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
