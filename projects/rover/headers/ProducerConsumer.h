#include <mutex>
#include <condition_variable>
#include <thread>

template <typename BufferType> class ProducerConsumer {
public:
  ProducerConsumer() {};
  ~ProducerConsumer() {};
  
  void initialise(std::function<BufferType> producer, std::function<BufferType> consumer) {
    this->producer = std::thread(producer(this->&buffer));
    this->consumer = std::thread(consumer(this->&buffer));
  };
  void terminate(){
    this->producer.join();
    this->consumer.join();
  };
    
private:
  enum Control {
    PRODUCER,
    CONSUMER
  } control;
  std::mutex mutex;
  std::condition_variable condition;
        
  std::thread producer;
  std::thread consumer;
  
  BufferType buffer;
  
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
}
