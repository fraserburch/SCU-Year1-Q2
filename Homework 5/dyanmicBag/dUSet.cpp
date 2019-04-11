#include "dUSet.h"


dUSet::dUSet(): dynamicBag(){

}


dUSet::dUSet(int a[], int sz): dynamicBag(a, sz){
  int numToErase;
  size_t numItemsErased = 0;
  for(int i = 0; i < sz-1; i++){
    for(int j = i+1; j < sz; j++){
      if(a[i] == a[j]){
        sz--;
        numToErase = a[i];
        for(int k = i; k < sz; k++){
          a[k] = a[k+1];
        }
        numItemsErased = erase_one(numToErase);
        j--;
        i--;
      }
    }
  }
}


void dUSet::insert(int target){
  erase(target);
  dynamicBag::insert(target);

}
