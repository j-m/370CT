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
  
  InterThreadVariable<unsigned int> encountered;
  bool running();
  
private:  
  std::thread overseer;
  void oversee();
  RoverCommands command;
  void resolve();
  
  std::thread multiple;
  std::thread wheelState;
  std::thread wheelHeight;
  std::thread wheelMotion;
  std::thread navigation;
  void checkForMultipleIssues();
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
