#ifndef DSET_H
#define DSET_H
#include "dUSet.h"
#include <string>

class dSet: public dUSet{
  public:
    dSet();

    dSet(int a[], int sz);

    void insert(int target);


};


#endif
