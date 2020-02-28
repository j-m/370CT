#include "./menu.h"

const int simulationCount = 0;

void threads() {
  std::cout << "Thread menu" << std::endl;
  if (simulationCount == 0) {
    std::cout << "There are currently no simulations running." << std::endl;
    return;
  }
  std::cout << "There are currently " << simulationCount << " simulations running." << std::endl;
  std::cout << "Enter a number 1-" << simulationCount << " to isolate output from that simulation."<< std::endl;
}

void scenarios() {
  std::cout << "Scenarios menu" << std::endl;
  std::cout << "1. Obstacle" << std::endl;
  std::cout << "2. Freewheel" << std::endl;
  std::cout << "3. Unresponsive wheel" << std::endl;
}

void quit() {
  exit(0);
}

void modes() {
  std::cout << "Mode menu" << std::endl;
  std::cout << "1. Random (single event)" << std::endl;
  std::cout << "2. Simulation (several random occurrences)" << std::endl;
  std::cout << "3. Automatic (1-3 sequentially)" << std::endl;
  for (int seconds = 5; seconds > 0; --seconds) {
    std::cout << "\r" << "Use 1-6 to select a scenario. Scenario 6 will automatically run in " << seconds << "second(s). Press any key to cancel" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void handleKey(const char key) {
  switch(key) {
    case 'm':
      modes();
      break;
    case 'q':
      quit();
      break;
    case 's':
      scenarios();
      break;
    case 't':
      threads();
      break;
    default:
      break;
  }
}

void listenToKeyPress() {
  while (true) {
    const char key = getchar();
    handleKey(key);
  }
}

void menuIntroduction() {
  std::cout << "At any time, press" << std::endl;
  std::cout << "  m for the mode menu" << std::endl;
  std::cout << "  q to quit" << std::endl;
  std::cout << "  s for the scenarios menu" << std::endl;
  std::cout << "  t for the thread menu" << std::endl;
  std::cout << std::endl;
  std::cout << "Menus will pause all simulations" << std::endl;
}

void Menu::initialise() {
  menuIntroduction();
  listenToKeyPress();
}
