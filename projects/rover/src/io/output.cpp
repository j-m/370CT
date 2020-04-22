#include "io.h"

std::thread IO::Output::consoleThread;
std::vector<std::string> IO::Output::messageBuffer;
InterThreadControl IO::Output::control;

void IO::Output::initialise() {
  IO::Output::consoleThread = std::thread(IO::Output::console);
}
 
void IO::Output::join() {
  IO::Output::control.notify();
  IO::Output::consoleThread.join();
}
