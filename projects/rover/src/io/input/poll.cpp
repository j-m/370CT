#include "global.h"
#include "io.h"

void IO::Input::Menu::poll() {
  while (true) {
    IO::Input::control.waitForControl(Control::CONSUMER);
    if (!Global::running) {
      break;
    }
    IO::Input::Menu::parseKey(IO::Input::keyboardBuffer);
    IO::Input::control.giveControlTo(Control::PRODUCER);
  }
}
