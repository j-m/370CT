#include <iostream>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <fstream>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable condVar;
int threadControlInt = 2;

void thread1() {
    using namespace std::this_thread;
    const int t1ID = 1;
    std::unique_lock<std::mutex> lck(mtx);
    while (threadControlInt!=t1ID) {
        condVar.wait(lck);
    }
    lck.unlock();
    cout << t1ID;
    sleep_for(std::chrono::seconds(2)); // introduced delay
    lck.lock();
    threadControlInt = 4;
    lck.unlock();
    condVar.notify_all();
}


int main(void) {

    thread t1(thread1); 

    t1.join();

    return 0;

}
