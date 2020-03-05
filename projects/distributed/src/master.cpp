#include "./master.h"
#include "./read.h"
#include "./log.h"
#include "./definitions.h"

#include <mpi.h>

void master() {
  std::vector<std::string> lines = read();
  
  myLogDefinitelyNotUsedByOtherThings("Starting to distribute work...\n");
  size_t lineIndex = 0;
  while (lineIndex < lines.size()) {
    for(int slave = 1; slave < sizeOfCluster; slave++){
      if (lineIndex >= lines.size()) {
        break;
      }
      const std::string line = lines.at(lineIndex);
      const char* message = line.c_str();
      const size_t messageLength = strlen(message);
      MPI_Send(&messageLength, 1, MPI_INT, slave, TAG_MESSAGE_LENGTH, MPI_COMM_WORLD);
      myLogDefinitelyNotUsedByOtherThings("Telling process % to expect a message of length %\n", slave, message);
      MPI_Send(message, (int)messageLength, MPI_CHAR, slave, TAG_MESSAGE, MPI_COMM_WORLD);
      myLogDefinitelyNotUsedByOtherThings("Sending process % message %\n", slave, message);
      lineIndex++;
    }
  }
}
