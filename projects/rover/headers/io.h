#pragma once
#include "common/ProducerConsumer.h"

#include <string>

namespace IO {
  void initialise();
  void join();
  
  namespace Output {
    void initialise();
    void join();
    
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
    void join();
    
    extern ProducerConsumer<char> keyboard;
    void listenToKeyPress();
    
    namespace Menu {
      void poll();
      void parseKey(char command);
    }
  }
}
