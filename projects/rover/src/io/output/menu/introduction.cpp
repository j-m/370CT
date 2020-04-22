#include "io.h"

void IO::Output::Menu::introduction() {  
  std::vector<std::string> messages = {
    "At any time press", 
    "  n for a new simulation",
    "  q to quit"
  };
  IO::Output::messages.waitForControl(Control::PRODUCER);
  IO::Output::messages.set(messages);
  IO::Output::messages.giveControlTo(Control::CONSUMER);
}
