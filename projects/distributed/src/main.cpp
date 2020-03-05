#include "./overhead.h"
#include "./master.h"
#include "./slave.h"
#include "./definitions.h"

int main(int argc, char** argv) {
  initialise(argc, argv);

  if (processRank == 0) {
    master();
  } else {
    slave();
  }
  
  finalize();
  return 0;
}
