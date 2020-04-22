#include "global.h"
#include "io.h"

void IO::Input::Menu::poll() {
  while (Global::running) {
    IO::Input::control.waitForControl(Control::CONSUMER);
    IO::Input::Menu::parseKey(IO::Input::keyboardBuffer);
    IO::Input::control.giveControlTo(Control::PRODUCER);
  }
}
