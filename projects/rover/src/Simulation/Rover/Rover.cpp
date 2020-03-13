#include "./Rover.h"
#include "./Movement/SteerableWheel.h"

#include <thread>

Rover::Rover() {
  std::thread wheelControlThread(&Rover::wheelControl, this); 
  std::thread movementControlThread(&Rover::movementControl, this); 
  std::thread navigationControlThread(&Rover::navigationControl, this); 
  std::thread sensorControlThread(&Rover::sensorControl, this); 
  std::thread groundControlThread(&Rover::groundControl, this); 
  std::thread arbiterThread(&Rover::arbiter, this); 
  wheelControlThread.join();
  movementControlThread.join();
  sensorControlThread.join();
  navigationControlThread.join();
  groundControlThread.join();
  arbiterThread.join();
}

void Rover::arbiter() {
  while (true) {
    groundControl();
    sensor();
    navigationControl();
  }
}
