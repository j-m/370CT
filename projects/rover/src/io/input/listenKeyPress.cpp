#include "global.h"
#include "io.h"

void IO::Input::listenToKeyPress() {
  while (Global::running) {
    IO::Input::keyboard.waitForControl(Control::PRODUCER);
    IO::Input::keyboard.buffer = getchar();
    IO::Input::keyboard.giveControlTo(Control::CONSUMER);
  }
}
