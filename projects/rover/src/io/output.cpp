#include "io.h"

std::thread IO::Output::consoleThread;
std::vector<std::string> IO::Output::messageBuffer;
InterThreadControl IO::Output::control;

std::thread IO::Output::fileThread;
std::vector<std::string> IO::Output::fileBuffer;
InterThreadControl IO::Output::fileControl;
std::ofstream IO::Output::file;

void IO::Output::initialise() {
  IO::Output::consoleThread = std::thread(IO::Output::console);
  IO::Output::file.open("log.txt", std::ofstream::out | std::ofstream::trunc);
  IO::Output::fileThread = std::thread(IO::Output::log);
}
 
void IO::Output::join() {
  IO::Output::file.close();
  IO::Output::control.notify();
  IO::Output::consoleThread.join();
  IO::Output::fileControl.notify();
  IO::Output::fileThread.join();
}
