#include "io.h"

ThreadWrapper IO::Output::consoleThread;
ProducerConsumer<std::vector<std::string>>> IO::Output::messages;

void IO::Output::initialise() {
  ThreadWrapper IO::Output::consoleThread = ThreadWrapper(std::thread(IO::Output::console));
}
 
void IO::Output::join() {
  IO::Output::consoleThread.join();
}
