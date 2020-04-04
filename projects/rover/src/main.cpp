#include "global.h"
#include "io/output.h"

int main(void) {
  Global::initialise();
  Output::introduction();
  return 0;
}
