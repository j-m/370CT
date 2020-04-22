#pragma once
#include "simulation/Flag.h"
#include "simulation/Simulation.h"

#include <vector>

namespace Simulations {
  void initialise();
  void join();
  
  void start(SimulationFlag flags = SimulationFlag::ALLOW_ALL);
  extern std::vector<Simulation*> list;
}
