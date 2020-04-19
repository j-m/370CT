#pragma once
#include <thread>

#include "common/InterThreadVariable.h"

class ThreadWrapper {
public:
  ThreadWrapper(std::thread* thread): thread(thread) {
    joined.set(false);
  };
  ~ThreadWrapper() {};
  
  void join() {
    if (joined.get() == false) {
      this.thread->join();
      joined.set(true);
    }
  }
    
private:
  std::thread* thread;
  InterThreadVariable<bool> joined;
};
