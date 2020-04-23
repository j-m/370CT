#include "./CartesianXYZ.h"

CartesianXYZ::CartesianXYZ(int xCoordinate, int yCoordinate, int zCoordinate):
  x(xCoordinate),
  y(yCoordinate),
  z(zCoordinate){ 
}

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

unsigned int CartesianXYZ::distance(CartesianXYZ point) {
  return (unsigned)((point - *this).square().sum());
}

std::string CartesianXYZ::string() {
  return std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z);
}
