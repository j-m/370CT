#include "Point.h"

Point::Point(int x, int y, int z): 
  current(CartesianXYZ(x,y,z)),
  target(CartesianXYZ(x,y,z)),
  original(CartesianXYZ(x,y,z))
{
    
}

void Point::moveCloserToTarget() {
  CartesianXYZ difference = this->target - this->current;
  CartesianXYZ differenceSquared = difference.square();
  if (differenceSquared.x > 0
   && differenceSquared.x >= differenceSquared.y
   && differenceSquared.x >= differenceSquared.z) {
    difference.x > 0 ? this->current.x++ : this->current.x--;
    return;
  }
  if (differenceSquared.y > 0
   && differenceSquared.y >= differenceSquared.x
   && differenceSquared.y >= differenceSquared.z) {
    difference.y > 0 ? this->current.y++ : this->current.y--;
    return;
  }
  if (differenceSquared.z > 0
   && differenceSquared.z >= differenceSquared.x
   && differenceSquared.z >= differenceSquared.y) {
    difference.z > 0 ? this->current.z++ : this->current.z--;
    return;
  }
}

void Point::setTarget(std::vector<Point*> &neighbours) {
  unsigned int closestDistanceSquared = UINT_MAX;
  Point* closestPoint;
    
  for (Point* neighbour : neighbours) {
    if (this == neighbour) {
      continue;
    }
    const unsigned int distanceSquared = neighbour->current.distance(this->current);
    if (distanceSquared < closestDistanceSquared) {
      closestDistanceSquared = distanceSquared;
      closestPoint = neighbour;
    }
  }

  this->target = this->current + (closestPoint->current - this->current) / 2;
}
