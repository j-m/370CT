#pragma once
#include <string>
#include <vector>

class CartesianXYZ {
  private:
    int x;
    int y;
    int z;
    
    CartesianXYZ square();
    int sum();
    
  public:
    CartesianXYZ(int xCoordinate, int yCoordinate, int zCoordinate): 
      x(xCoordinate), y(yCoordinate), z(zCoordinate){};

    friend CartesianXYZ operator+(const CartesianXYZ point1, const CartesianXYZ point2);
    friend CartesianXYZ operator-(const CartesianXYZ point1, const CartesianXYZ point2);
    friend CartesianXYZ operator/(const CartesianXYZ point, const int divisor);
    
    unsigned int distance(CartesianXYZ &point);
    void moveCloserTo(CartesianXYZ &point);
    CartesianXYZ findMidpointToClosestNeighbour(std::vector<CartesianXYZ*> &neighbours);
    std::string string();
};
