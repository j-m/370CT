#include "./WheelCommand.h"
#include "./SteerableWheelCommand.h"

class WheelCommandSet {
  public:
    WheelCommandSet();
    unsigned int value();
    
    SteerableWheelCommand wheelFrontLeftCommand;
    SteerableWheelCommand wheelFrontRightCommand;
    WheelCommand wheelMiddleLeftCommand;
    WheelCommand wheelMiddleRightCommand;
    SteerableWheelCommand wheelBackLeftCommand;
    SteerableWheelCommand wheelBackRightCommand;
}
