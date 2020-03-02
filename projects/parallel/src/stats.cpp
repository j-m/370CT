#include "./stats.h"

#include <thread>
#include <iostream>

void stats() {
  const unsigned int numberOfCores = std::thread::hardware_concurrency();
  const unsigned int clockSpeed = 0;
  const long systemRAM = 0;
  const unsigned int homeFolderMBs = 0;
  std::cout << "Total core count: " << numberOfCores << std::endl; 
  std::cout << "Core clock speed: " << clockSpeed << std::endl; 
  std::cout << "Total system RAM: " << systemRAM << "GB" << std::endl; 
  std::cout << "Home folder size: " << homeFolderMBs << std::endl; 
}
