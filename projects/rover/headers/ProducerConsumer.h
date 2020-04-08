#pragma once
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>

enum Control {
  PRODUCER,
  CONSUMER
};

template <typename BufferType> class ProducerConsumer {
public:
  ProducerConsumer() {};
  ~ProducerConsumer() {};
  BufferType buffer;
  
  void initialise(std::function<void()> producer, std::function<void()> consumer) {
    this->producer = std::thread(producer());
    this->consumer = std::thread(consumer());
  };
  void terminate(){
    this->producer.join();
    this->consumer.join();
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
      
  std::thread producer;
  std::thread consumer;
}
