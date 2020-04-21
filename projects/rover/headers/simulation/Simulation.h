#pragma once
#include "InterThreadVariable.h"
#include "simulation/Flag.h"

class Simulation {
public:
  Simulation(SimulationFlag flag): flags(flag) {};
  
  void initialise();
  void join();

private:
  SimulationFlag flags;
  Rover rover;
  unsigned int encountered;
  InterThreadVariable<bool> running;
  
  WheelState getRandomWheelState();
  void setWheelStates();
};