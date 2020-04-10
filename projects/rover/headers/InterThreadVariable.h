#pragma once
#include <mutex>

template <typename VariableType> class InterThreadVariable {
public:
  InterThreadVariable() {};
  ~InterThreadVariable() {};
  VariableType variable;
  
  void set(VariableType variable) {
    std::unique_lock<std::mutex> lock(this->mutex);
    this->variable = variable;
    lock.unlock();
  };
  
  VariableType get() {
    std::unique_lock<std::mutex> lock(this->mutex);
    VariableType variable = this->variable;
    lock.unlock();
    return variable;
  };
    
private:
  std::mutex mutex;
};
