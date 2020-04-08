#include "global.h"
#include "io.h"

int main(void) {
  Global::initialise();
  IO::Output::Menu::introduction();
  Global::join();
  return 0;
}
