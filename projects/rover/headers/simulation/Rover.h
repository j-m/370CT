#pragma once
#include <array>
#include <thread>

#include "global.h"
#include "common/InterThreadVariable.h"
#include "common/InterThreadControl.h"
#include "simulation/RoverCommand.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

class Rover {
public:
  Rover();
  
  void initialise();
  void join();

  InterThreadVariable<std::array<WheelState, Global::Constants::ROVER_NUMBER_OF_WHEELS>> states;
  InterThreadControl control;
  std::atomic<bool> finished;
  
private:
  unsigned int encountered;

  RoverCommands command;
  std::thread resolver;
  std::thread numberIssues;
  std::thread wheelState;
  std::thread wheelHeight;
  std::thread wheelMotion;
  std::thread navigation;
  void resolve();
  void checkNumberOfIssues();
  void checkForNavigationIssues();
  void checkForWheelHeightIssues();
  void checkForWheelStateIssues();
  void checkForWheelMotionIssues();
  
  void callForHelp();
  void liftWheel();
  void lowerWheel();
  void doNothing();
  void tryAgain();
  void changeDirection();
};
