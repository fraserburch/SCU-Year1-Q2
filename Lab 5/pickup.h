#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"
#include <string>

class Pickup: public Automobile{
  private:
    bool extCab;
    int haulCap;

  public:

    Pickup();
    Pickup(int haul, bool cab, std::string imake, std::string imodel, int iyear, double iprice, int istall);

    int getHaul(){
      return haulCap;
    }
    bool getCab(){
      return extCab;
    }
    bool park(bool lot[], int size);






};

#endif
