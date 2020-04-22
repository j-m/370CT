#include "global.h"
#include "io.h"
#include "simulations.h"

int main() {
  Global::initialise();
  IO::Output::Menu::introduction();
  while (Global::running) { }
  Global::join();
}
