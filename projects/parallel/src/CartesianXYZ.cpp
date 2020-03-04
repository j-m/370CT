#include "./CartesianXYZ.h"

CartesianXYZ operator+(const CartesianXYZ point1, const CartesianXYZ point2) {
	return CartesianXYZ(point1.x + point2.x, point1.y + point2.y, point1.z + point2.z);
}

CartesianXYZ operator-(const CartesianXYZ point1, const CartesianXYZ point2) {
  return CartesianXYZ(point1.x - point2.x, point1.y - point2.y, point1.z - point2.z);
}

CartesianXYZ operator/(const CartesianXYZ point, const int divisor) {
  return CartesianXYZ(point.x / divisor, point.y / divisor, point.z / divisor);
}

CartesianXYZ CartesianXYZ::square() {
  return CartesianXYZ(this->x * this->x, this->y * this->y, this->z * this->z);
}

int CartesianXYZ::sum() {
  return this->x + this->y + this->z;
}

unsigned int CartesianXYZ::distance(CartesianXYZ& point) {
  return (unsigned)((point - *this).square().sum());
}

void CartesianXYZ::moveCloserTo(CartesianXYZ& point) {
  CartesianXYZ difference = point - (*this);
  CartesianXYZ differenceSquared = difference.square();
  if (differenceSquared.x > 0
   && differenceSquared.x >= differenceSquared.y
   && differenceSquared.x >= differenceSquared.z) {
    difference.x > 0 ? this->x++ : this->x--;
    return;
  }
  if (differenceSquared.y > 0
   && differenceSquared.y >= differenceSquared.x
   && differenceSquared.y >= differenceSquared.z) {
    difference.y > 0 ? this->y++ : this->y--;
    return;
  }
  if (differenceSquared.z > 0
   && differenceSquared.z >= differenceSquared.x
   && differenceSquared.z >= differenceSquared.y) {
    difference.z > 0 ? this->z++ : this->z--;
    return;
  }
}

CartesianXYZ CartesianXYZ::findMidpointToClosestNeighbour(std::vector<CartesianXYZ*> &neighbours) {
  unsigned int closestDistanceSquared = UINT_MAX;
  CartesianXYZ closestPoint (0,0,0);
    
  for (CartesianXYZ* neighbour : neighbours) {
    if (this == neighbour) {
      continue;
    }
    const unsigned int distanceSquared = this->distance(*neighbour);
    if (distanceSquared < closestDistanceSquared) {
      closestDistanceSquared = distanceSquared;
      closestPoint = *neighbour;
    }
  }
  
//  printf("%s moving towards %s\n", this->string().c_str(), closestPoint->string().c_str());
  return ((closestPoint - (*this)) / 2);
}

std::string CartesianXYZ::string() {
  return std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z);
}
