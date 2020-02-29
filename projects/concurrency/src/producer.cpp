#include "./threadController.h"
#include "./producer.h"

#include <mutex>
#include <condition_variable>

unsigned int currentLineIndex = 0;
unsigned int currentCharacterIndex = 0;

void relinquishProducerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  thread = Thread::CONSUMER;
  mutexLock.unlock();
  producerConsumerSwitch.notify_all();
}

void produce(std::vector<std::string> lines) {
  finished = true;
}

void waitForProducerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  while (thread != Thread::PRODUCER) {
    producerConsumerSwitch.wait(mutexLock);
  }
  mutexLock.unlock();
}

void producer(std::vector<std::string> lines) {
  while (!finished) {
    waitForProducerControl();
    produce(lines);
    relinquishProducerControl();
  }
}
