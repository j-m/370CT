#include "./Rover.h"
#include "./Movement/SteerableWheel.h"

Rover::Rover() { }

void Rover::movementControl() {
  while (true) {
    
  }
}

void Rover::navigationControl() {
  while (true) {
    
  }
}

void Rover::sensor() {
  while (true) {
    
  }
}

void Rover::groundControl() {
  while (true) {
    
  }
}

void Rover::arbiter() {
  while (true) {
    groundControl();
    sensor();
    navigationControl();
    movementControl();
  }
}

void Rover::control() {
  std::thread movementControlThread(&Rover::MovementControl, this); 
  std::thread navigationControlThread(&Rover::NavigationControl, this); 
  std::thread sensorThread(&Rover::sensor, this); 
  std::thread groundControlThread(&Rover::GroundControl, this); 
  std::thread arbiterThread(&Rover::arbiter, this); 
  movementControlThread.join();
  navigationControlThread.join();
  obstacleControlThread.join();
  arbiterThread.join();
}
