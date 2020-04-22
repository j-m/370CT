#include "global.h"
#include "io.h"
#include "simulations.h"

int main() {
  Global::initialise();
  IO::Output::Menu::introduction();
  Simulations::start();
//  Global::join();
}
