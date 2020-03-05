#include "./SteerableWheel.h"

#include <iostream>
#include <thread>
#include <chrono>

const int MILLISECONDS_TO_ROTATE_1_DEGREE = 100;

SteerableWheel::SteerableWheel(std::string wheelID): Wheel(wheelID) {
  this->angle = 0;  
}

void SteerableWheel::rotateToAngle(const double targetAngle) {
  const double angleDifference = targetAngle - this->angle;
  if (angleDifference > 0) {
    std::thread rotateThread(&SteerableWheel::rotateClockWise, this, angleDifference); 
    rotateThread.join();
  } 
  if (angleDifference < 0) {
    std::thread rotateThread(&SteerableWheel::rotateCounterClockWise, this, -angleDifference); 
    rotateThread.join();
  }
}

void SteerableWheel::rotateClockWise(const double degrees) {
  for (unsigned int angleChangedBy = 0; angleChangedBy < degrees - 1; angleChangedBy++) {
    this->angle++;
    std::this_thread::sleep_for(std::chrono::milliseconds(MILLISECONDS_TO_ROTATE_1_DEGREE));
  }
}

void SteerableWheel::rotateCounterClockWise(const double degrees) {
  for (unsigned int angleChangedBy = 0; angleChangedBy < degrees - 1; angleChangedBy++) {
    this->angle--;
    std::this_thread::sleep_for(std::chrono::milliseconds(MILLISECONDS_TO_ROTATE_1_DEGREE));
  }
}
