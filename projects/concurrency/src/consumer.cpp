#include "./consumer.h"
#include "./threadController.h"

#include <mutex>
#include <condition_variable>

void relinquishConsumerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  thread = Thread::PRODUCER;
  mutexLock.unlock();
  producerConsumerSwitch.notify_all();
}

void consume() {
 
}

void waitForConsumerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  while (thread != Thread::CONSUMER) {
    producerConsumerSwitch.wait(mutexLock);
  }
  mutexLock.unlock();
}

void consumer() {
  while (!finished) {
    waitForConsumerControl();
    consume();
    relinquishConsumerControl();
  }
}
