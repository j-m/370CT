#pragma once
#include <thread>

#include "common/InterThreadControl.h"

enum Control {
  PRODUCER,
  CONSUMER
};

template <typename BufferType>
class ProducerConsumer : public InterThreadControl {
public:
  ProducerConsumer(): InterThreadControl() {};
  ~ProducerConsumer() {};
  BufferType buffer;
  
  void initialise(std::thread* producer, std::thread* consumer) {
    this->producer = producer;
    this->consumer = consumer;
  };
  void join(){
    this->producer->join();
    this->consumer->join();
  };
  
  BufferType get() {
    return this->buffer;
  }
  
  void set(BufferType buffer) {
    this->buffer = buffer;
  }
  
private:
  std::thread* producer;
  std::thread* consumer;
};
