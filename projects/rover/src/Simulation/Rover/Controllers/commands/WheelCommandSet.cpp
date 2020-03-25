#include "./WheelCommand.h"

unsigned int WheelCommandSet::value() {
  return this.wheelFrontLeftCommand * 100000 +
         this.wheelFrontRightCommand * 10000 +
         this.wheelMiddleLeftCommand * 1000 +
         this.wheelMiddleRightCommand * 100 +
         this.wheelBackLeftCommand * 10 +
         this.wheelBackRightCommand;
}
