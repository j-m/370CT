#include "./Log.h"

#include <iostream>

namespace Log {
  void message(std::string threadID, std::string message) {
    std::cout << threadID << " >> " << message << std::endl;
  }
}
