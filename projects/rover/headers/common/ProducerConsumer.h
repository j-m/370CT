#pragma once
#include <thread>

#include "common/ThreadWrapper.h"
#include "common/InterThreadControl.h"

template <typename BufferType>
class ProducerConsumer : InterThreadControl {
public:
  ProducerConsumer(): InterThreadControl() {};
  ~ProducerConsumer() {};
  BufferType buffer;
  
  void initialise(ThreadWrapper* producer, ThreadWrapper* consumer) {
    this->producer = producer;
    this->consumer = consumer;
  };
  void join(){
    this->producer->join();
    this->consumer->join();
  };
  
private:
  ThreadWrapper* producer;
  ThreadWrapper* consumer;
};
