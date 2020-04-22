#include "io.h"

void IO::Output::Menu::modes() {
  std::vector<std::string> messages = {
    "Mode menu", 
    "1. Random (single event)",
    "2. Simulation (several random occurrences)",
    "3. Automatic (1-3 sequentially)"
  };
  IO::Output::messages.waitForControl(Control::PRODUCER);
  IO::Output::messages.set(messages);
  IO::Output::messages.giveControlTo(Control::CONSUMER);
  for (int seconds = 5; seconds > 0; --seconds) {
    IO::Output::messages.waitForControl(Control::PRODUCER);
    IO::Output::messages.set({"\rUse 1-6 to select a scenario. Scenario 6 will automatically run in 5 second(s). Press any key to cancel"}); // TODO
    IO::Output::messages.giveControlTo(Control::CONSUMER);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
