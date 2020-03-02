#include <stdio.h>
#include <omp.h>

#include "./schedule.h"

#define sqr(x) ((x)*(x))

void schedule() {
  int arr[10]= {2,3,4,5,6,7,8,9,10};
  #pragma omp parallel 
  {
    int i = omp_get_thread_num();
    printf("%d: %d\n", i , sqr(arr[i]));
  }   
}
