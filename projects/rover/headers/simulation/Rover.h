#pragma once
#include <array>
#include <thread>

#include "global.h"
#include "InterThreadVariable.h"
#include "simulation/Wheel.h"

class Rover {
public:
  Rover();
  
  void initialise();
  void join();
  
private:
  unsigned int encountered;
  InterThreadVariable<bool> running;
  std::array<InterThreadVariable<int>,Global::Constants::ROVER_NUMBER_OF_WHEELS> states;
  std::array<Wheel, Global::Constants::ROVER_NUMBER_OF_WHEELS> wheels;
  
  std::thread arbiter;
  void arbitrate();
  
  void doNothing();
  void tryAgain();
  void changeDirection();
  void liftWheel();
  void lowerWheel();
  void callForHelp();
};
