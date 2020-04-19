#pragma once
#include <array>
#include <thread>

#include "global.h"
#include "common/InterThreadVariable.h"
#include "simulation/WheelState.h"

class Rover {
public:
  Rover();
  
  void initialise();
  void join();

  InterThreadVariable<std::array<WheelState, Global::Constants::ROVER_NUMBER_OF_WHEELS>> states;
  
private:
  InterThreadVariable<bool>* running;

  std::thread arbiter;
  void arbitrate();
  
  void doNothing();
  void tryAgain();
  void changeDirection();
  void liftWheel();
  void lowerWheel();
  void callForHelp();
};
