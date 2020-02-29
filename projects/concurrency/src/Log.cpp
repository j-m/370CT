#include "./Log.h"

#include <iostream>
#include <chrono>
#include <thread>

namespace Log {
  void message(std::string message) {
    std::cout << message << std::endl;
  }
  
  void messages(std::vector<std::string> messages, unsigned int delay) {
    for (std::string message: messages) {
      Log::message(message);
      std::this_thread::sleep_for(std::chrono::seconds(delay)); 
    }
  } 
}
