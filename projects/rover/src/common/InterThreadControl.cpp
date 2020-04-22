#include "common/InterThreadControl.h"

void InterThreadControl::waitForControl(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  while (this->control != control) {
    this->condition.wait(lock);
  }
  lock.unlock();
}

void InterThreadControl::giveControlTo(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  lock.lock();
  this->control = control;
  lock.unlock();
  this->condition.notify_all();
}
