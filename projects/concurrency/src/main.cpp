#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> lines;

void read() {
  std::ifstream infile("poem.txt");
  std::string line;
  while (std::getline(infile, line)) {
    lines.push_back(line);
  }
}

void display() {
  for (unsigned int index = 0; index < lines.size(); index++) {
    std::cout << lines.at(index) << std::endl;
  }
}

int main() {
  read();
  display();
  return 0;
}
