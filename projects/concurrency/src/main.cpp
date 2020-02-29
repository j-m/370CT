#include "./Log.h"
#include "./read.h"
#include "./producer.h"
#include "./consumer.h"
#include "./threadController.h"

#include <thread>

void quit() {
  while (!finished) {
    const char keypress = getchar();
    if (keypress == 'q') {
      exit(0);
    }
  }
  Log::message("Finished");
} 

int main() {
  std::thread quitThread(quit); 
  std::thread displayThread(Log::messages, read(), 1); 
  std::thread producerThread(producer, read()); 
  std::thread consumerThread(consumer);
  
  displayThread.join();
  producerThread.join();
  consumerThread.join();
  quitThread.join();
  return 0;
}
