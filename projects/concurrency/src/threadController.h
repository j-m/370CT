#pragma once

#include <mutex>
#include <condition_variable>

static constexpr int BUFFER_SIZE = 1;
enum Thread { CONSUMER, PRODUCER };

extern Thread thread;
extern std::mutex producerConsumerMutex;
extern std::condition_variable producerConsumerSwitch;
extern char buffer[BUFFER_SIZE];
extern bool finished;
