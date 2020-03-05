#include "./BatteryChargeLevelIndicator.h"
#include "./Compass.h"
#include "./Geolocator.h"
#include "./Odometer.h"
#include "./SteeringAngleSensor.h"

class Data {
  private:
    BatteryChargeLevelIndicator batteryChargeLevelIndicator;
    Compass compass;
    Geolocator geolocator;
    
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
    
  public:
    Data();
};
