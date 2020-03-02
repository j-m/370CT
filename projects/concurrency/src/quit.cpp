#include "./quit.h"
#include "./Log.h"
#include "./threadController.h"

void quit() {
  while (!finished) {
    const char keypress = getchar();
    if (keypress == 'q') {
      exit(0);
    }
  }
  Log::message("Finished");
} 
