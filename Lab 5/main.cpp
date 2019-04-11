#include "pickup.h"
#include "van.h"
#include <iostream>
using namespace std;
int main(){
  bool parkSpots[8] = {true, false, true, false, false, true, true, false};
  Automobile test =  Automobile();
  bool thisBool = test.park(parkSpots, 8);
  cout<<(thisBool)<<endl;

  //Testing Pickup Class
  Pickup loadedTruck = Pickup(10000, true, "Ford", "F-150", 2019, 43760.98, 2);
  Pickup defaultTruck = Pickup();
  cout << loadedTruck.getCab() << endl;
  cout << loadedTruck.getHaul() << endl;

  loadedTruck.park(parkSpots, 8);
  cout<<loadedTruck.getStall() <<endl;


  //Testing Van Class
  Van defaultVan = Van();
  Van bigVan = Van(10, "Honda", "MiniVan", 2018, 12760.98, 3);
  Van smallVan = Van(6, "Honda", "MiniVan", 2018, 12760.98, 5);
  bool vanParkSpots[8] = {true, false, true, false, false, true, true, false};
  bool bigVanParkSpots[8] = {true, false, true, false, false, true, true, false};
  smallVan.park(vanParkSpots, 8);
  bigVan.park(bigVanParkSpots, 8);
  cout<<"Small van parked: " << smallVan.getStall() <<endl;
  cout<<"Big van parked: " <<bigVan.getStall() <<endl;

    return(0);
}
