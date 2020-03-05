#include "./Rover.h"
#include "./SteerableWheel.h"
#include "../io/Log.h"

unsigned int roverID = 0;
const float METRES_PER_WHEEL_REVOLUTION = 0.8;

Rover::Rover() { }

void Rover::movementControl() {
  while (true) {
    
  }
}

void Rover::navigationControl() {
  while (true) {
    
  }
}

void Rover::obstacleControl() {
  while (true) {
    
  }
}

void Rover::sensor() {
  while (true) {
    
  }
}

void Rover::arbiter() {
  while (true) {
    
  }
}

void Rover::control() {
  std::thread movementControlThread(&Rover::MovementControl, this); 
  std::thread navigationControlThread(&Rover::NavigationControl, this); 
  std::thread obstacleControlThread(&Rover::ObstacleControl, this); 
  std::thread sensorThread(&Rover::sensor, this); 
  std::thread arbiterThread(&Rover::arbiter, this); 
  movementControlThread.join();
  navigationControlThread.join();
  obstacleControlThread.join();
  arbiterThread.join();
}
