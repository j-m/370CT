#include <iostream>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <fstream>
#include <chrono>
#include <mutex>
#include <condition_variable>

const int THREAD_ID = 1;

std::mutex mtx;
std::condition_variable condVar;
int threadControlInt = 1;

void menu() {
  std::unique_lock<std::mutex> mutexLock(mtx);
  while (threadControlInt != THREAD_ID) {
      condVar.wait(mutexLock);
  }
  mutexLock.unlock();
  std::cout << thread1ID;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  mutexLock.lock();
  threadControlInt = 4;
  mutexLock.unlock();
  condVar.notify_all();
}


int main(void) {
  std::thread menuThread(menu); 
  menuThread.join();
  return 0;
}
