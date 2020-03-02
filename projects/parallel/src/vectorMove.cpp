#include <stdio.h>
#include <omp.h>
#include <vector>

#include "./vectorMove.h"
#include "./Cartesian_xyz.h"

std::vector<Cartesian_xyz*> vectors = {
  new Cartesian_xyz(  5,  14,  10),
  new Cartesian_xyz(  7,  -8, -14),
  new Cartesian_xyz( -2,   9,   8),
  new Cartesian_xyz( 15,  -6,   3),
  new Cartesian_xyz( 12,   4,  -5),
  new Cartesian_xyz(  4,  20,  17),
  new Cartesian_xyz(-16,   5,  -1),
  new Cartesian_xyz(-11,   3,  16),
  new Cartesian_xyz(  3,  10, -19),
  new Cartesian_xyz(-16,   7,   4)
};

void vectorMove() {
  int arr[10]= {2,3,4,5,6,7,8,9,10};
  #pragma omp parallel 
  {
    int i = omp_get_thread_num();
    printf("%d: %d\n", i , arr[i]);
  }   
}
