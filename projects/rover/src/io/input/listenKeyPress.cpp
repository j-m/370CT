#include "global.h"
#include "io.h"

void IO::Input::listenToKeyPress() {
  while (true) {
    IO::Input::control.waitForControl(Control::PRODUCER);
    if (!Global::running) {
      break;
    }
    IO::Input::keyboardBuffer = getchar();
    IO::Input::control.giveControlTo(Control::CONSUMER);
  }
}
