#include <iostream>
#include <omp.h>
#include <vector>

#include "./vectorMove.h"
#include "Point.h"

const unsigned int MAX_ITERATIONS = 60;

std::vector<Point*> points = {
  new Point(  5,  14,  10),
  new Point(  7,  -8, -14),
  new Point( -2,   9,   8),
  new Point( 15,  -6,   3),
  new Point( 12,   4,  -5),
  new Point(  4,  20,  17),
  new Point(-16,   5,  -1),
  new Point(-11,   3,  16),
  new Point(  3,  10, -19),
  new Point(-16,   7,   4)
};

void movePoints() {
  #pragma omp parallel for schedule (dynamic, 1)
  for (int threadPointIndex = 0; threadPointIndex < points.size(); threadPointIndex++) {
    points[threadPointIndex]->moveCloserToTarget();
  }
}

void setPointTargets() {
  for (Point* point : points) {
    point->setTarget(points);
  }
}

void printCurrentPoints() {
  for (Point* point : points) {
    std::cout << point->current.string() << std::endl;
  }
  std::cout << std::endl;
}

void printPointTransition() {
  for (Point* point : points) {
    std::cout << point->original.string() << " targetted " << point->target.string() << " and ended up at " << point->current.string() << std::endl;
  }
  std::cout << std::endl;
}

void vectorMove() {
  setPointTargets();
  for (unsigned int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
    movePoints();
    if (iteration == 5
     || iteration == 10
     || iteration == 20) {
      std::cout << "Iteration " << iteration << std::endl;
      printCurrentPoints();
    }
  }
  printPointTransition();
}
