#pragma once
#include <vector>
#include <string>
#include <thread>
#include <fstream>

#include "common/InterThreadControl.h"

namespace IO {
  void initialise();
  void join();
  
  namespace Output {
    void initialise();
    void join();

    extern InterThreadControl control;
    extern std::vector<std::string> messageBuffer;
    extern std::thread consoleThread;
    void console();
    
    extern InterThreadControl fileControl;
    extern std::vector<std::string> fileBuffer;
    extern std::ofstream file;
    extern std::thread fileThread;
    void log();
    
    namespace Menu {     
      void introduction();
      void modes();
      void scenarios();
    }
  }
  
  namespace Input {
    void initialise();
    void join();
    
    extern char keyboardBuffer;
    extern std::thread listener;
    extern std::thread handler;
    extern InterThreadControl control;
    void listenToKeyPress();
    
    namespace Menu {
      void poll();
      void parseKey(char command);
    }
  }
}
