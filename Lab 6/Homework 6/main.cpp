//main.cpp
#include "nDPoint.h"
#include <iostream>

using namespace std;

int main(){
  int arrInt[2] = {1,2};
  int arrInt2[2] = {2,1};
  nDPoint<int> one = nDPoint<int>(2, arrInt);
  nDPoint<int> equalToOne = nDPoint<int>(2, arrInt);
  nDPoint<int> two = nDPoint<int>(2, arrInt2);

  nDPoint<int> onePlustwo = one+two;
  cout<<"Testing B4 '+' Operator" <<endl;
    cout<< "("<<onePlustwo.getItemAt(0)<< ", " <<onePlustwo.getItemAt(1) <<")"<<endl;


  cout<<"" <<endl;


  cout<<"Testing B4 '==' Operator" <<endl;
  if(equalToOne == one){
    cout<< "The two are equal" <<endl;
  }


  cout<<"" <<endl;


  cout<<"Testing B5 Distance Function for ints" <<endl;
  int arr1[2] = {1,1};
  int arr2[2] = {2,2};
  nDPoint<int> point1 = nDPoint<int>(2, arr1);
  nDPoint<int> point2 = nDPoint<int>(2, arr2);

  double distanceBet = distance(point1, point2);

  cout <<distanceBet <<endl;


  cout<<"" <<endl;


  cout<<"Testing B5 Distance Function for strings" <<endl;
  string arrStr[1] = {"aa"};
  string arrStr2[1] = {"bb"};
  nDPoint<string> pointStr1 = nDPoint<string>(1, arrStr);
  nDPoint<string> pointStr2 = nDPoint<string>(1, arrStr2);

  double distanceBetSTR = distance(pointStr1, pointStr2);

  cout <<distanceBetSTR <<endl;


  return 0;
}
