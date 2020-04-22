#include "global.h"
#include "common/InterThreadControl.h"

InterThreadControl::InterThreadControl(unsigned int initialController)
 :control(initialController) {
  
}

void InterThreadControl::waitForControl(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  while (this->control != id) {
    this->condition.wait(lock);
  }
}

void InterThreadControl::giveControlTo(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  this->control = id;
  this->condition.notify_all();
}
