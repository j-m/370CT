#include <iostream>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <fstream>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable condVar;
int threadControlInt = 2;

void thread1() {
  const int thread1ID = 1;
  std::unique_lock<std::mutex> mutexLock(mtx);
  while (threadControlInt != thread1ID) {
      condVar.wait(mutexLock);
  }
  mutexLock.unlock();
  std::cout << thread1ID;
  std::this_threadsleep_for(std::chrono::seconds(2));
  mutexLock.lock();
  threadControlInt = 4;
  mutexLock.unlock();
  condVar.notify_all();
}


int main(void) {
  std::thread t1(thread1); 
  t1.join();
  return 0;
}
