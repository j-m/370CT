#pragma once
#include "ProducerConsumer.h"

#include <vector>
#include <string>

namespace IO {
  void initialise();
  void terminate();
  
  namespace Output {
    namespace Menu {     
      void introduction();
    }
  }
  
  namespace Input {
    ProducerConsumer<std::vector<std::string>> keyboard;
    
    void listenToKeyPress();
    namespace Menu {
      void poll();
      void parseKey(char command);
    }
  }
}
