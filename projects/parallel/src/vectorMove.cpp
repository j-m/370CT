#include <iostream>
#include <omp.h>
#include <vector>

#include "./vectorMove.h"
#include "CartesianXYZ.h"

const unsigned int MAX_ITERATIONS = 60;

std::vector<CartesianXYZ*> points = {
  new CartesianXYZ(  5,  14,  10),
  new CartesianXYZ(  7,  -8, -14),
  new CartesianXYZ( -2,   9,   8),
  new CartesianXYZ( 15,  -6,   3),
  new CartesianXYZ( 12,   4,  -5),
  new CartesianXYZ(  4,  20,  17),
  new CartesianXYZ(-16,   5,  -1),
  new CartesianXYZ(-11,   3,  16),
  new CartesianXYZ(  3,  10, -19),
  new CartesianXYZ(-16,   7,   4)
};

void movePoints() {
  #pragma omp parallel for schedule (dynamic, 1)
  for (int threadPointIndex = 0; threadPointIndex < points.size(); threadPointIndex++) {
    CartesianXYZ* currentPoint = points[threadPointIndex];
    currentPoint->moveCloserTo(currentPoint->findMidpointToClosestNeighbour(points));
  }
}

void printPoints() {
  for (CartesianXYZ* point : points) {
    std::cout << point->string() << std::endl;
  }
  std::cout << std::endl;
}

void vectorMove() {
  for (unsigned int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
    movePoints();
    if (iteration % 10 == 0) {
      printPoints();
    }
  }
}
