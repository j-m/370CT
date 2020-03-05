#include "./Sensors/BatteryChargeLevelIndicator.h"
#include "./Sensors/Compass.h"
#include "./Sensors/Geolocator.h"
#include "./Sensors/Odometer.h"
#include "./Sensors/SteeringAngleSensor.h"

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
}
