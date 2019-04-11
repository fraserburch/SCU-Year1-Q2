//nDPoint.h
#ifndef NDPOINT_H
#define NDPOINT_H

#include <cstdlib>
#include <string>

template <typename T>
class nDPoint {

  private:
    T arrayofT[10];
    int n;


  public:
    nDPoint();

    nDPoint(int dimension);

    nDPoint(int dimension, T a[]);

    T getItemAt(int index){return arrayofT[index];}

    int getSize(){return n;}

    operator =(nDPoint arr);

    operator +=(nDPoint arr);
};


template <typename T>
nDPoint<T>::nDPoint(){
  n = 0;
}

template <typename T>
nDPoint<T>::nDPoint(int dimension){
    n = dimension;
    T y = T();
    for(int i = 0; i < dimension; ++i){
      arrayofT[i] = y;
    }

}

template <typename T>
nDPoint<T>::nDPoint(int dimension, T a[]){
  n = dimension;
  for(int i = 0; i < dimension; ++i){
    arrayofT[i] = a[i];
  }

}

//T must be able to use the = operator
template <typename T>
nDPoint<T>::operator =(nDPoint arr){
    n = arr.getSize();
    for(int i = 0; i < n; ++i){
      arrayofT[i] = arr.getItemAt(i);
    }
}

//T must be able to use the += operator
template <typename T>
nDPoint<T>::operator +=(nDPoint arr){
    if(n < arr.getSize()){
        n = arr.getSize();
    }
    for(int i = 0; i < n; ++i){
      arrayofT[i] += arr.getItemAt(i);
    }
}

#endif
