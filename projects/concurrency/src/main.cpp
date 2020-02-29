#include "./Log.h"
#include "./read.h"
#include "./producer.h"
#include "./consumer.h"
#include "./quit.h"
#include "./threadController.h"

#include <thread>

int main() {
  const std::vector<std::string> lines = read();

  std::thread quitThread(quit); 
  std::thread displayThread(Log::messages, lines, 1); 
  std::thread producerThread(producer, lines); 
  std::thread consumerThread(consumer);
  
  displayThread.join();
  producerThread.join();
  consumerThread.join();
  quitThread.join();
  return 0;
}
