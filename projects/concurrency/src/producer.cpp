#include "./threadController.h"
#include "./producer.h"

#include <mutex>
#include <condition_variable>
#include <iostream>

std::vector<std::string> lines;
unsigned int currentLineIndex = 0;
unsigned int currentCharacterIndex = 0;

void relinquishProducerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  thread = Thread::CONSUMER;
  mutexLock.unlock();
  producerConsumerSwitch.notify_all();
}

char getNextCharacterToSend() {
  if (currentLineIndex > lines.size()) {
    return ' ';
  }
  if (currentCharacterIndex > lines.at(currentLineIndex).size()) {
    currentLineIndex++;
    currentCharacterIndex = 0;
    return '\n';
  }
  return lines.at(currentLineIndex)[currentCharacterIndex++];
}

void produce() {
  if (currentLineIndex > lines.size()) {
    finished = true;
  }
  for (unsigned int bufferIndex = 0; bufferIndex < BUFFER_SIZE; bufferIndex++) {
    const char nextCharacterToSend = getNextCharacterToSend();
    std::cout << "Putting " << nextCharacterToSend << " on the buffer" << std::endl;
    buffer[bufferIndex] = nextCharacterToSend;
  }
}

void waitForProducerControl() {
  std::unique_lock<std::mutex> mutexLock(producerConsumerMutex);
  while (thread != Thread::PRODUCER) {
    producerConsumerSwitch.wait(mutexLock);
  }
  mutexLock.unlock();
}

void producer(const std::vector<std::string> data) {
  lines = data;
  while (!finished) {
    waitForProducerControl();
    produce();
    relinquishProducerControl();
  }
}
