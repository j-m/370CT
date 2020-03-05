#include "./master.h"
#include "./read.h"
#include "./log.h"
#include "./definitions.h"

#include <mpi.h>

void tellEachSlaveHowManyLinesToExpect(const size_t totalNumberOfLines) {
  for(int slave = 0; slave < CLUSTER_SIZE; slave++) {
    if (slave == MASTER_RANK) {
      continue;
    }
    size_t numberOfLines = totalNumberOfLines / SLAVE_COUNT;
    if (totalNumberOfLines % SLAVE_COUNT < slave) {
      numberOfLines++;
    }
    MPI_Send(&numberOfLines, 1, MPI_INT, slave, TAG_NUMBER_OF_LINES, MPI_COMM_WORLD);
    myLogDefinitelyNotUsedByOtherThings("Telling slave % to expect % lines\n", slave, numberOfLines);
  }
}

void sendLineToSlave(const int slave, const std::string line) {
  const char* message = line.c_str();
  const int messageLength = (int)strlen(message);
  MPI_Send(message, messageLength, MPI_CHAR, slave, TAG_LINE, MPI_COMM_WORLD);
  myLogDefinitelyNotUsedByOtherThings("Sending slave % line (length %) \"%\"\n", slave, messageLength, message);
}

void distributeLines(std::vector<std::string> lines) {
  myLogDefinitelyNotUsedByOtherThings("Starting to distribute work...\n");
  size_t lineIndex = 0;
  while (lineIndex < lines.size()) {
    for(int slave = 0; slave < CLUSTER_SIZE; slave++){
      if (slave == MASTER_RANK) {
        continue;
      }
      if (lineIndex >= lines.size()) {
        break;
      }
      std::string line = lines.at(lineIndex);
      sendLineToSlave(slave, line);
      lineIndex++;
    }
  }
}

void master() {
  const std::vector<std::string> lines = read();
  tellEachSlaveHowManyLinesToExpect(lines.size());
  distributeLines(lines);
}
