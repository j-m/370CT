#include "io/input.h"

void Input::listenToKeyPress() {
  while (true) {
    waitForControl(Input::Control::HANDLER);
    Input::key = getchar();
    giveControlTo(Input::Control::LISTENER);
  }
}
