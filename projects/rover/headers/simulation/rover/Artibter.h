#include "headers/simulation/rover/commands/WheelCommandSet.h"

#include <thread>

class Arbiter {
public:
  Arbiter();
  ~Arbiter();
private:
  std::thread navigationControlThread;
  std::thread sensorControlThread;
  std::thread groundControlThread; 
  std::thread arbiterThread;
  
  WheelCommandSet navigationWheelCommandSet;
  WheelCommandSet sensorWheelCommandSet;
  WheelCommandSet groundWheelCommandSet;
  
  void arbitrate();  
  void navigationControl();
  void sensorControl();
  void groundControl();  
};
