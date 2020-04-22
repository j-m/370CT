#include "global.h"
#include "io.h"

void IO::Input::Menu::poll() {
  while (Global::running.get()) {
    IO::Input::keyboard.waitForControl(Control::CONSUMER);
    IO::Input::Menu::parseKey(IO::Input::keyboard.get());
    IO::Input::keyboard.giveControlTo(Control::PRODUCER);
  }
}
