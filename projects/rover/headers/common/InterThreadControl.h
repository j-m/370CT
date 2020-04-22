#pragma once
#include <mutex>
#include <condition_variable>

class InterThreadControl {
public:
  InterThreadControl(unsigned int initialController = 0);
  ~InterThreadControl() {};

  void waitForControl(unsigned int id);
  void giveControlTo(unsigned int id);
    
private:
  unsigned int control;
  std::mutex mutex;
  std::condition_variable condition;
};
