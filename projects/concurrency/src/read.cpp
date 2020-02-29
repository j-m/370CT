#include "./read.h"

#include <fstream>

std::vector<std::string> read() {
  std::vector<std::string> lines;
  std::ifstream infile("./poem.txt");
  std::string line;
  while (std::getline(infile, line)) {
    lines.push_back(line);
  }
  return lines;
}
