#include "simulations.h"

std::vector<Simulation*> Simulations::list;

void Simulations::initialise() {
  
}
 
void Simulations::join() {
  for (Simulation* simulation: Simulations::list) {
    simulation->join();
  }
}

void Simulations::start(SimulationFlag flags) {
  Simulations::list.push_back(new Simulation(flags));
}
