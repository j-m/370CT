#include "./Camera.h"
#include "./Odometer.h"
#include "./SteeringAngleSensor.h"

class SensoryArray {
  public:
    SensoryArray();
    
    Camera camera;

    Odometer frontLeftOdometer;
    Odometer frontRightOdometer;
    Odometer middleLeftOdometer;
    Odometer middleRightOdometer;
    Odometer backLeftOdometer;
    Odometer backRightOdometer;
    
    SteeringAngleSensor frontLeftAngleSensor;
    SteeringAngleSensor frontRightAngleSensor;
    SteeringAngleSensor backLeftAngleSensor;
    SteeringAngleSensor backRightAngleSensor;
};
