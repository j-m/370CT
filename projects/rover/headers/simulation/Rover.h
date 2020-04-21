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
  Rover(InterThreadVariable<bool>* simulationRunning): running(simulationRunning){};
  
  void initialise();
  void join();

  InterThreadVariable<std::array<WheelState, Global::Constants::ROVER_NUMBER_OF_WHEELS>> states;
  InterThreadVariable<unsigned int>* encountered;
  
private:
  InterThreadControl control;
  InterThreadVariable<bool>* running;
  
  std::thread overseer;
  void oversee();
  RoverCommands resolution
  
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
