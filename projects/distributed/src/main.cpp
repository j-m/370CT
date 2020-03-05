#include "./read.h"

#include <stdio.h>
#include <mpi.h>

int processRank;
int sizeOfCluster;
std::vector<std::string> lines = read();

void master() {
  size_t lineIndex = 0;
  while (lineIndex < lines.size()) {
    for(int slave = 1; slave < sizeOfCluster; slave++){
      const std::string line = lines.at(lineIndex++);
      MPI_Send(&lineIndex, 1, MPI_INT, slave, 0, MPI_COMM_WORLD);
      printf("Telling slave %d to read line %d\n", slave, (int)lineIndex);
    }
  }
}

void slave() {
  int lineIndex;
  while (lineIndex < lines.size()) {
    MPI_Recv(&lineIndex, 1, MPI_INT, 0, processRank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Slave %d reading line %d\n", processRank, lineIndex);
  }
}

int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &sizeOfCluster);
  MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

  if (processRank == 0) {
    master();
  } else {
    slave();
  }
  
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  return 0;
}
