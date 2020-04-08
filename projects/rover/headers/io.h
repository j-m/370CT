#pragma once
#include "ProducerConsumer.h"

#include <string>

namespace IO {
  void initialise();
  void terminate();
  
  namespace Output {
    void initialise();
    void terminate();
    
    void console(std::string message);
    
    namespace Menu {     
      void introduction();
      void modes();
      void scenarios();
      void threads();
    }
  }
  
  namespace Input {
    void initialise();
    void terminate();
    
    extern ProducerConsumer<char> keyboard;
    void listenToKeyPress();
    
    namespace Menu {
      void poll();
      void parseKey(char command);
    }
  }
}
