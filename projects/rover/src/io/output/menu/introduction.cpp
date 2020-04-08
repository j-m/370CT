#include "io.h"

#include <iostream>

void IO::Output::Menu::introduction() {
  /*
  lock mutex
  add to display queue
  */
  
  std::cout << "At any time, press" << std::endl;
  //std::cout << "  m for the mode menu" << std::endl;
  std::cout << "  n for a new simulation" << std::endl;
  std::cout << "  q to quit" << std::endl;
  //std::cout << "  s for the scenarios menu" << std::endl;
  std::cout << "  t for the thread menu" << std::endl;
  std::cout << std::endl;
  //std::cout << "Menus will pause all simulations" << std::endl;
  
  /*
  unlock mutext
  */
}
