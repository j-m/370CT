#pragma once
#include "InterThreadVariable.h"

class Wheel {
public:
  Wheel() {};
  
  void initialise(InterThreadVariable<bool>* roverRunning, InterThreadVariable<int>* roverWheelState);
  void loop();
  void join();

private:
  InterThreadVariable<bool>* running;
  InterThreadVariable<int>* state;
  
  std::thread thread;
};
