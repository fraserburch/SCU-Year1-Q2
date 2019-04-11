#ifndef VAN_H
#define VAN_H
#include "automobile.h"
#include <string>


class Van: public Automobile{

  private:
    int seats;

  public:
    Van();
    Van(int numSeats, std::string imake, std::string imodel, int iyear, double iprice, int istall);
    int getSeats(){return seats;}

    bool park(bool lot[], int size);


};
#endif
