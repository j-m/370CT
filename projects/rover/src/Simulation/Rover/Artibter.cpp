#include "./WheelCommandSet.h"

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
 
 
#include "./Controller.h"

void Arbiter::arbitrate() {
  while (true) {
    this.groundControl();
    this.sensorControl();
    this.navigationControl();
  }
}

#include "./Controller.h"

#include <thread>

Controller::Controller():
  navigationControlThread(&Controller::navigationControl, this),
  sensorControlThread(&Controller::sensorControl, this),
  groundControlThread(&Controller::groundControl, this),
  arbiterThread(&Controller::arbiter, this)
{
  
}

Controller::~Controller() {
  try {
    sensorControlThread.join();
    navigationControlThread.join();
    groundControlThread.join();
    arbiterThread.join();
  } catch(){
    
  }
}
