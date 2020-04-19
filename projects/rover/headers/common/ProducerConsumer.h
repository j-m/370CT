#pragma once
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>

#include "common/ThreadWrapper.h"

enum Control {
  PRODUCER,
  CONSUMER
};

template <typename BufferType> class ProducerConsumer {
public:
  ProducerConsumer() {};
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
  
  void waitForControl(Control control) {
    std::unique_lock<std::mutex> lock(this->mutex);
    while (this->control != control) {
      this->condition.wait(lock);
    }
    lock.unlock();
  };
  void giveControlTo(Control control) {
    std::unique_lock<std::mutex> lock(this->mutex);
    lock.lock();
    this->control = control;
    lock.unlock();
    this->condition.notify_all();
  };
    
private:
  Control control;

  std::mutex mutex;
  std::condition_variable condition;
      
  ThreadWrapper* producer;
  ThreadWrapper* consumer;
};
