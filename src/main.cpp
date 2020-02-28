#include "./io/menu.h"
#include "./io/quit.h"
#include "./rover/Rover.h"

#include <iostream>

int main(void) {
  std::thread menuThread(menu); 
  menuThread.join();
  return 0;
}
