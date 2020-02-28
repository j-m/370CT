#include "./Wheel.h"
#include "../io/Log.h"

Wheel::Wheel(std::string wheelID): id(wheelID) {
  this->wheelSpeed = 0;
}

void Wheel::log(std::string message) {
  Log::message(this->id, message);
}
