#include "./consumer.h"
#include "./threadController.h"

#include <mutex>
#include <condition_variable>
#include <iostream>

std::string poem;

void relinquishConsumerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  thread = Thread::PRODUCER;
  mutexLock.unlock();
  producerConsumerSwitch.notify_all();
}

void consume() {
  for (unsigned int bufferIndex = 0; bufferIndex < BUFFER_SIZE; bufferIndex++) {
    const char bufferCharacter = buffer[bufferIndex];
    std::cout << "Taking " << bufferCharacter << " off the buffer" << std::endl;
    poem += bufferCharacter;
    std::cout << "Current poem: " << poem << std::endl;
    buffer[bufferIndex] = 0;
  }
}

void waitForConsumerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  while (thread != Thread::CONSUMER) {
    producerConsumerSwitch.wait(mutexLock);
  }
  mutexLock.unlock();
}

void consumer() {
  poem = "";
  while (!finished) {
    waitForConsumerControl();
    consume();
    relinquishConsumerControl();
  }
}
