#include "./io/menu.h"
#include "./rover/Rover.h"

#include <iostream>

int main(void) {
  std::thread menuThread(Menu::initialise); 
  menuThread.join();
  return 0;
}
