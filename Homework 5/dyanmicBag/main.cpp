#include "dUSet.h"
#include "dSet.h"
#include <iostream>
using namespace std;

int main(){
cout<<"____________________________________________________"<<endl;
cout<<"Testing Problem 2, Constructor with array parameter"<<endl;
cout<<"____________________________________________________"<<endl;
cout<<""<<endl;
int arr[10] = {1,3,2,6,3,2,1,6,2,6};
dUSet firstDUSet = dUSet(arr, 10);
cout<<"Array we start with: ";
for(int i = 0; i < 10; i++){
  cout<<arr[i] << ", ";
}
cout<<""<<endl;
cout<<"This is the set that automatically erases duplicates: ";
cout<<firstDUSet<<endl;
cout<<""<<endl;
cout<<""<<endl;


cout<<"____________________________________________________"<<endl;
cout<<"Testing Problem 2, overloaded insert function"<<endl;
cout<<"____________________________________________________"<<endl;
cout<<""<<endl;
cout << "Set we start with: " << firstDUSet << endl;
cout << "Inserting a number that exists in the set (3): ";
firstDUSet.insert(3);
cout << firstDUSet <<endl;
cout << "Inserting a number that does NOT exist in the set (4): ";
firstDUSet.insert(4);
cout << firstDUSet <<endl;
cout<<""<<endl;
cout<<""<<endl;


cout<<"____________________________________________________"<<endl;
cout<<"Testing Problem 3, Constructors"<<endl;
cout<<"____________________________________________________"<<endl;
dSet baseDSet = dSet();
int unsortedArray[12] = {4,2,3,1,5,1,1,2,3,4,2,2};
cout<<"Array we start with: ";
for(int i = 0; i < 12; i++){
  cout<<unsortedArray[i] << ", ";
}
cout<<""<<endl;
dSet sortedDSet = dSet(unsortedArray, 12);
cout<<"Sorted set: " << sortedDSet<<endl;


cout<<"____________________________________________________"<<endl;
cout<<"Testing Problem 3, Insert Function"<<endl;
cout<<"____________________________________________________"<<endl;
cout<<"Inserting 10 into the set." <<endl;
sortedDSet.insert(10);
cout<<"Set after inserting         10         : " << sortedDSet<<endl;

cout<<"Inserting 2 into the set." <<endl;
sortedDSet.insert(2);
cout<<"Set after inserting         2         : " << sortedDSet<<endl;

cout<<"Inserting 8 into the set." <<endl;
sortedDSet.insert(8);
cout<<"Set after inserting         8         : " << sortedDSet<<endl;

cout<<"Inserting 200 into the set." <<endl;
sortedDSet.insert(200);
cout<<"Set after inserting         200         : " << sortedDSet<<endl;

cout<<"Inserting 16 into the set." <<endl;
sortedDSet.insert(16);
cout<<"Set after inserting         16         : " << sortedDSet<<endl;

cout<<"Inserting 14 into the set." <<endl;
sortedDSet.insert(14);
cout<<"Set after inserting         14         : " << sortedDSet<<endl;

cout<<"Inserting 12 into the set." <<endl;
sortedDSet.insert(12);
cout<<"Set after inserting         12         : " << sortedDSet<<endl;

return(0);
}
