#pragma once
#include "InterThreadVariable.h"

namespace Global {
  enum Constants {
    PROBLEMS_PER_SIMULATION = 5,
    ROVER_NUMBER_OF_WHEELS = 6
  };
  extern InterThreadVariable<bool> running;
  
  void initialise();
  void join();
  void quit();
}
