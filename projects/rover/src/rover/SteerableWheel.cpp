#include "./SteerableWheel.h"

#include <iostream>
#include <thread>
#include <chrono>

const int MILLISECONDS_TO_ROTATE_1_DEGREE = 100;
const double PROBABILITY_UNRESPONSIVE = 0.0001;

SteerableWheel::SteerableWheel(std::string wheelID): Wheel(wheelID) {
  this->angle = 0;  
}

void SteerableWheel::rotateToAngle(const double targetAngle) {
  if (PROBABILITY_UNRESPONSIVE) {
    //TODO
  }
  const double angleDifference = targetAngle - this->angle;
  if (angleDifference > 0) {
    std::thread menuThread(&SteerableWheel::rotateClockWise, this, angleDifference); 
    menuThread.join();
  } 
  if (angleDifference < 0) {
    std::thread menuThread(&SteerableWheel::rotateCounterClockWise, this, angleDifference * -1); 
    menuThread.join();
  }
}

void SteerableWheel::rotateClockWise(const double degrees) {
  for (unsigned int angleChangedBy = 0; angleChangedBy < degrees - 1; angleChangedBy++) {
    this->angle--;
    std::this_thread::sleep_for(std::chrono::milliseconds(MILLISECONDS_TO_ROTATE_1_DEGREE));
  }
}

void SteerableWheel::rotateCounterClockWise(const double degrees) {
  for (unsigned int angleChangedBy = 0; angleChangedBy < degrees - 1; angleChangedBy++) {
    this->angle++;
    std::this_thread::sleep_for(std::chrono::milliseconds(MILLISECONDS_TO_ROTATE_1_DEGREE));
  }

}