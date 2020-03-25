#include "./Rover.h"

#include <thread>

Rover::Rover():
  controlThread(&Rover::controlThread, this),
  sensorArrayThread(&Rover::sensorArray, this),
  wheelThread(&Rover::movementControl this)
{
  
}

Rover::~Rover() {
  try {
    wheelControlThread.join();
    movementControlThread.join();
  } catch(){
    
  }
}
