#include "pickup.h"


Pickup::Pickup(): Automobile(){
  haulCap = 0;
  extCab = false;
}
Pickup::Pickup(int haul, bool cab, std::string imake, std::string imodel, int iyear, double iprice, int istall): Automobile(imake, imodel, iyear, iprice, istall){
  haulCap = haul;
  extCab = cab;
}

bool Pickup::park(bool lot[], int size){
    int spot=size;
    for(int i = 0; i < size-1; i++){
      if(lot[i] == false && lot[i+1] == false){
        spot = i;
      }
    }
    if(spot != size){
      setStall(spot);
      lot[spot] = true;
      lot[spot+1] = true;
      return (true);
    }
      return false;

  }
