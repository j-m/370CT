#include "./CartesianXYZ.h"

CartesianXYZ* CartesianXYZ::delta(CartesianXYZ* point) {
  return new CartesianXYZ(point->x - this->x, point->y - this->y, point->z - this->z);
}

CartesianXYZ* CartesianXYZ::square() {
  return new CartesianXYZ(this->x * this->x, this->y * this->y, this->z * this->z);
}

int CartesianXYZ::sum() {
  return this->x + this->y + this->z;
}

unsigned int CartesianXYZ::distance(CartesianXYZ* point) {
  return (unsigned)this->delta(point)->square()->sum();
}

void CartesianXYZ::moveCloserTo(CartesianXYZ* point) {
  CartesianXYZ* difference = this->delta(point);
  CartesianXYZ* differenceSquared = difference->square();
  if (differenceSquared->x > differenceSquared->y
   && differenceSquared->y > differenceSquared->z) {
      difference->x > 0 ? this->x++ : this->x--;
      return;
  }
  if (differenceSquared->y > differenceSquared->z) {
    difference->y > 0 ? this->y++ : this->y--;
    return;
  }
  difference->z > 0 ? this->z++ : this->z--;
}

std::string CartesianXYZ::string() {
  return std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z);
}
