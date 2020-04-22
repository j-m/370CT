#include "global.h"
#include "common/InterThreadControl.h"

InterThreadControl::InterThreadControl(unsigned int initialController)
 :control(initialController) {
  
}

void InterThreadControl::waitForControl(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  this->condition.wait(lock, [this, id]{ return control != id;});
  lock.unlock();
}

void InterThreadControl::giveControlTo(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  this->control = id;
  lock.unlock();
  this->condition.notify_all();
}
