#include "./slave.h"
#include "./log.h"
#include "./definitions.h"

#include <mpi.h>

void slave() {
  MPI_Status status;
  size_t lineIndex = 0;
  while (true) {
    MPI_Recv(&lineIndex, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    if (status.MPI_TAG == TAG_TERMINATE) {
      myLogDefinitelyNotUsedByOtherThings("Finish-OFF tag received!");
      break;
    } else {
      myLogDefinitelyNotUsedByOtherThings("Slave %d reading line %d", processRank, (int)lineIndex); 
    }
  }
  myLogDefinitelyNotUsedByOtherThings("Slave %d finished work", processRank);
}
