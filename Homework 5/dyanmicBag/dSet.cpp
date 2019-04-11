#include "dSet.h"

dSet::dSet(): dUSet(){
}

dSet::dSet(int a[], int sz): dUSet(){
  int tmp;

  //erase duplicates
  for(int i = 0; i < sz-1; i++){
    for(int j = i+1; j < sz; j++){
      if(a[i] == a[j]){
        sz--;
        for(int k = i; k < sz; k++){
          a[k] = a[k+1];
        }
        j--;
        i--;
      }
    }
  }
  //Fill array in ascending order
  for(int i = 0; i < sz-1; i++){
    for(int j = i+1; j < sz; j++){
      if(a[i] > a[j]){
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        j--;
      }
    }
  }

  //using InsertAt to fill dSet
  for(size_type i = 0; i < sz; i++){
    dynamicBag::insertAt(a[i], i);
  }
}

void dSet::insert(int target){
  size_type moveCounter = 0;
  if(count(target) == 0){
    for(int i = 0; i < target; ++i){
      if(count(i) == 1){
        moveCounter++;
      }
    }
    dynamicBag::insertAt(target, moveCounter);
  }
}
