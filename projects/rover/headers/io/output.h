#include "ProducerConsumer.h"

#include <string>

namespace Output {
  ProducerConsumer DisplayProducerConsumer;
  ProducerConsumer LogProducerConsumer;

  void initialise();
  void terminate();
  
  void display(std::string message);
  void log(std::string message);
  
  void introduction();
  void menu();
}
