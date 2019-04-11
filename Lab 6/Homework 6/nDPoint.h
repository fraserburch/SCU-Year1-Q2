//nDPoint.h
#ifndef NDPOINT_H
#define NDPOINT_H

#include <cstdlib>
#include <string>
#include <cmath>

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

    nDPoint<T> operator =(nDPoint<T> arr);

    void operator +=(nDPoint<T> arr);
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
nDPoint<T> nDPoint<T>::operator =(nDPoint arr){
    n = arr.getSize();
    for(int i = 0; i < n; ++i){
      arrayofT[i] = arr.getItemAt(i);
    }
    return *this;
}

//T must be able to use the += operator
template <typename T>
void nDPoint<T>::operator +=(nDPoint arr){
    if(n < arr.getSize()){
        n = arr.getSize();
    }
    for(int i = 0; i < n; ++i){
      arrayofT[i] += arr.getItemAt(i);
    }
    //return *this;
}


//T must be able to use the + operator
template <typename T>
nDPoint<T> operator +(nDPoint<T> a1, nDPoint<T> a2){
  nDPoint<T> newNpoint;
  newNpoint += a1;
  newNpoint += a2;
  return newNpoint;
}

//T must be able to use the = operator
template <typename T>
bool operator ==(nDPoint<T> a1, nDPoint<T> a2){
  int counter = 0;
  if(a1.getSize() == a2.getSize()){
    for(int i = 0; i < a1.getSize(); ++i){
      if (a1.getItemAt(i) == a2.getItemAt(i)){
        counter++;
      }
    }
  }
  if(counter == a1.getSize()){
    return true;
  }
  return false;
}

//overloading - for string
int operator - (const std::string& a1, const std::string& a2);

template <typename T>
double distance(nDPoint<T> a1, nDPoint<T> a2){
  double toReturn;
  double sumToSqrt = 0.0;
  T a1H;
  T a2H;
  if(a1.getSize() == a2.getSize()){
    for(int i = 0; i < a1.getSize(); i++){
      a1H = (a1.getItemAt(i));
      a2H = (a2.getItemAt(i));
      sumToSqrt += double(pow((a1H - a2H),2));
    }
    toReturn = sqrt(sumToSqrt);
  }
  return toReturn;
}



#endif
