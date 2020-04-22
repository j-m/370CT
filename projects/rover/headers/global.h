#pragma once
#include <atomic>
#include "common/InterThreadVariable.h"

namespace Global {
  enum Constants {
    PROBLEMS_PER_SIMULATION = 5,
    ROVER_NUMBER_OF_WHEELS = 6,
    PERCENTAGE_PROBABILITY_WHEEL_ISSUE = 20,
    PERCENTAGE_PROBABILITY_RESOLVE_ISSUE = 40
  };
  extern std::atomic<bool> running;
  
  void initialise();
  void quit();
  void join();
}
