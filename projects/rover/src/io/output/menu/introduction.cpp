#include "io.h"

void IO::Output::Menu::introduction() {  
  std::vector<std::string> messages;
    messages.push_back("At any time press");
    messages.push_back("  n for a new simulation");
    messages.push_back("  q to quit");
  IO::Output::control.waitForControl(Control::PRODUCER);
  IO::Output::messageBuffer = messages;
  IO::Output::control.giveControlTo(Control::CONSUMER);
}
