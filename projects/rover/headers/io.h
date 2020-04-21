#pragma once
#include "common/ProducerConsumer.h"

#include <vector>
#include <string>

namespace IO {
  void initialise();
  void join();
  
  namespace Output {
    void initialise();
    void join();

    extern ProducerConsumer<std::vector<std::string>> messages;
    extern std::thread consoleThread;
    void console();
    
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
