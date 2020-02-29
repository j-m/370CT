#include "./threadController.h"

Thread thread = Thread::PRODUCER;
std::mutex producerConsumerMutex;
std::condition_variable producerConsumerSwitch;
char buffer[BUFFER_SIZE];
bool finished = false;
