#include "io.h"

void IO::Input::Menu::threads() {
  std::cout << "Thread menu" << std::endl;
  if (simulations.size() == 0) { 
    std::cout << "There are currently no simulations running." << std::endl;
    return; 
  }
  std::cout << "There are currently " << simulations.size() << " simulations running." << std::endl;
  std::cout << "Enter a number 1-" << simulations.size() << " to isolate output from that simulation."<< std::endl;
}
