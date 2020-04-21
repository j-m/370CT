#pragma once
#include <mutex>
#include <condition_variable>

class InterThreadControl {
public:
  InterThreadControl(unsigned int initialController = 0): control(initialController) {};
  ~InterThreadControl() {};
  
  void waitForControl(unsigned int id) {
    std::unique_lock<std::mutex> lock(this->mutex);
    while (this->control != control) {
      this->condition.wait(lock);
    }
    lock.unlock();
  };
  
  void giveControlTo(unsigned int id) {
    std::unique_lock<std::mutex> lock(this->mutex);
    lock.lock();
    this->control = control;
    lock.unlock();
    this->condition.notify_all();
  };
    
private:
  unsigned int control;
  std::mutex mutex;
  std::condition_variable condition;
};
