#pragma once

#include <string>
#include <vector>

namespace Log {
  void message(std::string message);  
  void messages(std::vector<std::string> messages, unsigned int delay = 0);  
}
