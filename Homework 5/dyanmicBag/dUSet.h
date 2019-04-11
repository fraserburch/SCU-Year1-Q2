#ifndef DUSET_H
#define DUSET_H
#include "dynamicBag.h"
#include <string>

class dUSet: public dynamicBag{

  public:
  // default constructor
  // pre: none
  // post: creates an empty dynamicBag
  dUSet();

  // constructor that creates a dUSet out of an array of integers
  // pre: size must match the size of the array
  // post: creates a new dUSet which is a copy of the array passed in
  dUSet(int a[], int sz);

  // pre: none
  // post: adds a copy of target to this dynamicBag if, and only if,
          //the int passed in doesn't exist in the set
  void insert(int target);

};


#endif
