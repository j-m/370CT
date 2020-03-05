#include "./overhead.h"
#include "./master.h"
#include "./slave.h"
#include "./definitions.h"

int main(int argc, char** argv) {
  initialise(argc, argv);
  if (PROCESS_RANK == MASTER_RANK) {
    master();
  } else {
    for(int slaveNumber = 1; slaveNumber < CLUSTER_SIZE; slaveNumber++) {
      slave(slaveNumber);
    }
  }
  finalize();
  return 0;
}
