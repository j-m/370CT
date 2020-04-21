#include "io.h"

std::thread IO::Output::consoleThread;
ProducerConsumer<std::vector<std::string>> IO::Output::messages;

void IO::Output::initialise() {
  IO::Output::consoleThread = std::thread(IO::Output::console);
}
 
void IO::Output::join() {
  IO::Output::consoleThread.join();
}
