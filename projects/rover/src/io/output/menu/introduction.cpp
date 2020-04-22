#include "io.h"

#include <iostream>
#include <vector>
#include <string>

void IO::Output::Menu::introduction() {
  
  std::vector<std::string> messages = {
    "At any time press", 
    "  n for a new simulation",
    "  q to quit"
  };
  IO::Output::messages.waitForControl(Control::PRODUCER);
  IO::Output::messages.buffer = messages;
  IO::Output::messages.waitForControl(Control::CONSUMER);
}
