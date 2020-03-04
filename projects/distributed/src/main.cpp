#include "./read.h"

#include <fstream>
#include <stdio.h>
#include <mpi.h>

int processRank, sizeOfCluster;

void master() {


}

void slave() {

}

int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &sizeOfCluster);
  MPI_Comm_rank(MPI_COMM_WORLD, &processRank);
  printf("Test\n");
  
  
  std::ofstream outputFile("out.txt");
  outputFile << "test \n ";
  
  const std::vector<std::string> lines = read();
  unsigned int lineIndex = 0;
  while (lineIndex < lines.size()) {
    if(processRank == 0){
      for(int cluster = 1; cluster < sizeOfCluster; cluster++){
        const std::string line = lines.at(lineIndex++);
        const char* message = line.c_str();
        const size_t messageLength = strlen(message);
        MPI_Send(&messageLength, 1, MPI_INT, cluster, 0, MPI_COMM_WORLD);
        MPI_Send(message, (int)messageLength, MPI_CHAR, cluster, 0, MPI_COMM_WORLD);
        outputFile << "Sending " << message << "\n";
        printf("Message sent: %s\n", message);
      }
    } else {
      int messageLength;
      MPI_Recv(&messageLength, 1, MPI_INT, 0, processRank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      char* message = (char*)malloc(messageLength + 1);
      MPI_Recv(&message, messageLength, MPI_CHAR, 0, processRank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("Message received: %s\n", message);
      outputFile << "Receiving " << message << "\n";
    }
  }
  
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  return 0;
}
