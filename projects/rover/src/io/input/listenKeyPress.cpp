#include "global.h"
#include "io.h"

void IO::Input::listenToKeyPress() {
  while (Global::running) {
    IO::Menu.waitForControl(Control::PRODUCER);
    IO::Menu.buffer = getchar();
    IO::Menu.giveControlTo(Control::CONSUMER);
  }
}
