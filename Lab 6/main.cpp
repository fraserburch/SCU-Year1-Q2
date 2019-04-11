//main.cpp
#include "nDPoint.h"
#include <iostream>

using namespace std;


// T1 must be able to have == operator
// T2 must be able to be set to integer type value
template <typename T1, typename T2>
T2 countExact(T1 a[], T2 size, T1 find){
  T2 count = 0;
  for(T2 i = 0; i < size; ++i){
    if(a[i] == find){
      count++;
    }
  }
  return count;
}


// T1 must be able to have <= and >= operator
// T2 must be able to be set to integer type value
template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high){
  int count = 0;
  for(T2 i = 0; i < size; ++i){
    if(a[i] <= high && a[i] >= low){
      count++;
    }
  }
  return count;
}


int main(){
  //Testing Problem 1
cout<< "TESTING PROBLEM 1" << endl;
int arr[6] = {6,2,3,2,6,2};
int thisIndex = countExact(arr, 6, 2);
string ar[3] = {"hey","hello","howdy"};
string toFind = "hello";
int thisIndex2 = countExact(ar, 3, toFind);
cout << thisIndex << endl;
cout << thisIndex2;


//Testing Problem 2
cout<< "TESTING PROBLEM 2" << endl;
int arrInt1[6] = {6,2,3,2,6,2};
int counter1 = count_range(arrInt1, 6, 1,3);
string arrString1[4] = {"a","b","howdy", "c"};
string toFindLow = "a";
string toFindTop = "c";
int counter2 = count_range(arrString1, 4, toFindLow, toFindTop );
cout << counter1 << endl;
cout << counter2;




    nDPoint<int> defaultPoint = nDPoint<int>();

    int arrr[4] = {1,2,3,4};
    nDPoint<int> numDims = nDPoint<int>(4,arrr);

    int arrInt[5] = {1,2,3,4,5};

    nDPoint<int> fullIntConstructor = nDPoint<int>(5, arrInt);

    string arrString[5] = {"test","test1","test2","test3","test4"};

    nDPoint<string> fullStringConstructor = nDPoint<string>(5, arrString);

    numDims += fullIntConstructor;

    int sizeOfIntArray = numDims.getSize();
    int sizeOfStringArray = fullStringConstructor.getSize();

    cout<< "Size of int array: " << sizeOfIntArray << endl;
    cout<< "Size of string array: " << sizeOfStringArray << endl;

    int shouldBe3 = numDims.getItemAt(2);
    cout<< "Should be 6, it is: " << shouldBe3 <<endl;




  return 0;
}
