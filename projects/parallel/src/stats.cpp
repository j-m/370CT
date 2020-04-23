#include "./stats.h"

#include <thread>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

const char* fileName = "output.txt";

std::string run(std::string command) {
  std::system((command +  ">>" + fileName).c_str());
  std::ifstream file(fileName);
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::remove(fileName);
  return buffer.str();
}

void stats() {
  const unsigned int numberOfCores = std::thread::hardware_concurrency();
  std::string clockSpeed;
  std::string systemRAM;
  std::string homeFolderMBs;
  
#ifdef __linux__ 
  clockSpeed = run("cat /proc/cpuinfo | grep \"cpu MHz\"");
  systemRAM = run("free -t");
  homeFolderMBs = run(" df -h --total");
#else

#endif

  std::cout << "Total core count: " << numberOfCores << std::endl; 
  std::cout << "Core clock speed: " << clockSpeed << std::endl; 
  std::cout << "Total system RAM: " << systemRAM << "GB" << std::endl; 
  std::cout << "Home folder size: " << homeFolderMBs << std::endl; 
}
