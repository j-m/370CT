#pragma once
#include "common/InterThreadVariable.h"
#include "simulation/Flag.h"
#include "simulation/Rover.h"

class Simulation {
public:
  Simulation(SimulationFlag flag): flags(flag) {};
  
  void initialise();
  void join();

private:
  SimulationFlag flags;
  Rover rover;
  unsigned int encountered;
  
  WheelState getRandomWheelState();
  void setWheelStates();
};
