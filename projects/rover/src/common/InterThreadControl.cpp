#include "global.h"
#include "common/InterThreadControl.h"

InterThreadControl::InterThreadControl(unsigned int initialController)
 :control(initialController) {
  
}

void InterThreadControl::waitForControl(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  this->condition.wait(lock, [this, id]{ return control == id || !Global::running; });
}

void InterThreadControl::giveControlTo(unsigned int id) {
  std::unique_lock<std::mutex> lock(this->mutex);
  this->control = id;
  this->condition.notify_all();
}

void InterThreadControl::notify() {
  this->condition.notify_all();
}
