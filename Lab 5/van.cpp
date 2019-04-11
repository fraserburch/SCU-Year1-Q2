#include "van.h"


Van::Van(): Automobile(){
  seats = 0;
}

Van::Van (int numSeats, std::string imake, std::string imodel, int iyear, double iprice, int istall):
Automobile(imake, imodel, iyear, iprice, istall){
  seats = numSeats;
}

  bool Van::park(bool lot[], int size){
    if(seats <= 7){
      return (Automobile::park(lot, size));
    }
    else{
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
      }
      return false;
    }
