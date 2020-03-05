#include "./slave.h"
#include "./log.h"
#include "./definitions.h"

#include <mpi.h>
#include <string>

size_t getNumberOfLines() {
  MPI_Status status;
  size_t numberOfLines = 0;
  MPI_Recv(&numberOfLines, 1, MPI_INT, MASTER_RANK, TAG_NUMBER_OF_LINES, MPI_COMM_WORLD, &status);
  return numberOfLines;
}

std::string getLine() {
  MPI_Status status;
  MPI_Probe(MASTER_RANK, TAG_LINE, MPI_COMM_WORLD, &status);
  int count;
  MPI_Get_count(&status, MPI_CHAR, &count);
  char* buffer = (char*)malloc(sizeof(char) * count);
  MPI_Recv(buffer, count, MPI_CHAR, MASTER_RANK, TAG_LINE, MPI_COMM_WORLD, &status);
  std::string line(buffer);
  free(buffer);
  return line;
}

void slave(int slaveNumber) {
  const size_t numberOfLines = getNumberOfLines();
  for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++) {
    std::string line = getLine();
    myLogDefinitelyNotUsedByOtherThings("Slave % received message %\n", slaveNumber, line);
  }
}
