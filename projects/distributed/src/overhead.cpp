#include "./overhead.h"
#include "./log.h"
#include "./definitions.h"

#include <mpi.h>

void finalize() {
  MPI_Barrier(MPI_COMM_WORLD);
  int result = MPI_Finalize();
  if (result != 0) {
    myLogDefinitelyNotUsedByOtherThings("Finalizing the MPI system failed, aborting now...\n");
    MPI_Abort(MPI_COMM_WORLD, result);
  }
}

void initialise(int argc, char **argv) {
  int result = MPI_Init(&argc, &argv);
  if (result != 0) {
    myLogDefinitelyNotUsedByOtherThings("Error while initializing the system. Aborting now...\n");
    MPI_Abort(MPI_COMM_WORLD, result);
  }
  MPI_Comm_size(MPI_COMM_WORLD, &sizeOfCluster);
  MPI_Comm_rank(MPI_COMM_WORLD, &processRank);
}
