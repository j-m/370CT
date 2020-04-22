#include "global.h"
#include "io.h"

void IO::Input::listenToKeyPress() {
  while (Global::running.get()) {
    IO::Input::control.waitForControl(Control::PRODUCER);
    IO::Input::keyboardBuffer = getchar();
    IO::Input::control.giveControlTo(Control::CONSUMER);
  }
}
