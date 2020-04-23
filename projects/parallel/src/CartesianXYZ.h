#pragma once
#include <string>
#include <vector>

class CartesianXYZ {
  public:
    CartesianXYZ(int xCoordinate, int yCoordinate, int zCoordinate);

    int x;
    int y;
    int z;

    friend CartesianXYZ operator+(const CartesianXYZ point1, const CartesianXYZ point2);
    friend CartesianXYZ operator-(const CartesianXYZ point1, const CartesianXYZ point2);
    friend CartesianXYZ operator/(const CartesianXYZ point, const int divisor);
    
    CartesianXYZ square();
    std::string string();
    int sum();
    unsigned int distance(CartesianXYZ point);
};
