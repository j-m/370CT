#pragma once
#include <string>
#include <vector>

#include "CartesianXYZ.h"

class Point {
  public:
    Point(int xCoordinate, int yCoordinate, int zCoordinate);

    CartesianXYZ current;
    CartesianXYZ target;
    CartesianXYZ original;

    unsigned int distance(Point &point);
    void moveCloserToTarget();
    void setTarget(std::vector<Point*> &neighbours);
};
