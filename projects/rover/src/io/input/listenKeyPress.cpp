#include "global.h"
#include "io.h"

void IO::Input::listenToKeyPress() {
  while (Global::running) {
    IO::Input::control.waitForControl(Control::PRODUCER);
    IO::Input::keyboardBuffer = getchar();
    IO::Input::control.giveControlTo(Control::CONSUMER);
  }
}
