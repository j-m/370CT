#include "global.h"
#include "io.h"

void IO::Input::Menu::poll() {
  while (Global::running) {
    IO::Input::keyboard.waitForControl(Control::CONSUMER);
    IO::Input::Menu::parse(IO::Input::keyboard.buffer);
    IO::Input::keyboard.giveControlTo(Control::PRODUCER);
  }
}
