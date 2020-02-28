#include "./io/menu.h"

#include <thread>

int main(void) {
  std::thread menuThread(Menu::initialise); 
  menuThread.join();
  return 0;
}
