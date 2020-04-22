#pragma once
#include "common/InterThreadVariable.h"
#include "simulation/Flag.h"
#include "simulation/Rover.h"

#include <thread>

class Simulation {
public:
  Simulation(SimulationFlag flag);
  
  void join();

private:
  SimulationFlag flags;
  Rover rover;
  unsigned int encountered;
  std::thread thread;
  
  void loop();
  
  WheelState getRandomWheelState();
  void setWheelStates();
};
