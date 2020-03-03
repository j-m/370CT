#pragma once
#include <string>

class CartesianXYZ {
  private:
    int x;
    int y;
    int z;
    
    CartesianXYZ* delta(CartesianXYZ* point);
    CartesianXYZ* square();
    int sum();
    
  public:
    CartesianXYZ(int xCoordinate, int yCoordinate, int zCoordinate): 
      x(xCoordinate), y(yCoordinate), z(zCoordinate){};

    unsigned int distance(CartesianXYZ* point);
    void moveCloserTo(CartesianXYZ* point);
    std::string string();
};
