#include "./Rover.h"
#include "./Movement/SteerableWheel.h"

#include <thread>

Rover::Rover() { }

void Rover::navigationControl() {
  // Path finder
}

void Rover::sensor() {
  // Detect at destination 
  
  // Issues occur when
  // data - previousData != predictedData
  
  // Possible issues
  // Off course (angle) -> rectify -> call for help 
  // Off course (position) -> rectify -> call for help 
  // Freewheel (odometer too high) -> go around -> call for help
  // Blocked by obstacle. (odometer too low) -> go around -> if odometer is the same again then wheel is unresponsive -> call for help
  // Wheel cannot go forwards motor issue -> try again -> call for help
  // Wheel cannot go forwards power issue -> wait for charge -> call for help
  // Wheel cannot go backwards motor issue -> try again -> call for help
  // Wheel cannot go backwards power issue -> wait for charge -> call for help
  // Wheel cannot turn motor issue (unexpected SAS)-> try again -> call for help
  // Wheel cannot turn power issue -> wait for charge -> call for help
  // Power depleating too quickly 
}

void Rover::groundControl() {
  // Check incoming messages
  // Override sensor
  // Override navigator
}

void Rover::arbiter() {
  while (true) {
    groundControl();
    sensor();
    navigationControl();
  }
}

void Rover::control() {
  std::thread movementThread(&Rover::movement, this); 
  std::thread movementControlThread(&Rover::movementControl, this); 
  std::thread navigationControlThread(&Rover::navigationControl, this); 
  std::thread sensorThread(&Rover::sensor, this); 
  std::thread groundControlThread(&Rover::groundControl, this); 
  std::thread arbiterThread(&Rover::arbiter, this); 
  movementThread.join();
  movementControlThread.join();
  navigationControlThread.join();
  groundControlThread.join();
  arbiterThread.join();
}
