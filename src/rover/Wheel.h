#pragma once

#include <string>

class Wheel {
  protected:
    std::string id;
    signed char wheelSpeed;
    
    void log(std::string message);
    
  public:
    Wheel(std::string wheelID);
};
