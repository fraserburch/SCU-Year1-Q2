#include "dbiguint.h"
#include <iostream>
using namespace std;
int main(){
  string str = "10";
  string str2 = "100";
  dbiguint defaultConst = dbiguint();
  dbiguint small = dbiguint(str);
  dbiguint big = dbiguint(str2);


  /*
  ----------------------Testing Problem 10------------------------------------------
  */
cout<<"____________________________________________________"<<endl;
cout<<"Testing Problem 1 from homework ten, which is problem 10"<<endl;
 cout<<"from lab 4.   It is overloading the '>>' operator."<<endl;
cout<<"____________________________________________________"<<endl;
  dbiguint pTen;
  cout<< "Created dbiguint pTen. printing pTen to show it is empty: " << pTen << endl;
  cin >> pTen;
  cout<< "Printing the dbiguint pTen: " << pTen << endl;
  return (0);
}

//----------------------START OF PROBLEM 2------------------------------------------
/*
cout<<"--------Start of Problem 2--------"<<endl;
  cout <<"Comparing " << small << " to " << big <<endl;
    cout<<endl;
  int resultOfCompare = small.compare(big);
  cout << "Should be -1. " << resultOfCompare<<endl;

  bool test1 = (small < big); //Should be true
  cout<< "Should be true " << test1 << endl;

  bool test3 = (small <= big); //Should be true
  cout<< "Should be true " << test3 << endl;

  bool test4 = (small != big); //Should be true
  cout<< "Should be true " << test4 << endl;

  bool test5 = (small == big); //Should be false
  cout<< "Should be false " << test5 << endl;

  bool test6 = (small > big);//Should be false
  cout<< "Should be false " << test6 << endl;

  bool test7 = (small >= big); //Should be false
  cout<< "Should be false " << test7 << endl;

  //Testing the overloaded operator (+)
  dbiguint added = small+big;
  cout<< added << endl;

  //Testing copy constructor
  dbiguint copyOfBig = dbiguint(big);
  cout<<"This should be a copy of Big("<<big<<")"<< copyOfBig<<endl;

  //Testing the overloaded = operator
  dbiguint copyOfSmall = small;
  cout<<"This should be a copy of Small("<<small<<")"<<copyOfSmall<<endl;
*/
/*
----------------------END OF PROBLEM 2------------------------------------------
*/


/*
----------------------START OF PROBLEM 3------------------------------------------
*/
/*
cout<<"--------Start of Problem 3--------"<<endl;
//Testing modified reserve
  string reserveTest = "178";
  string reserve2Test = "9999999";

  dbiguint small22 = dbiguint(reserveTest);
  dbiguint big22 = dbiguint(reserve2Test);

  small22.reserve(big22.size());
  for(size_t i = 0; i < small22.size(); i++){
    cout<<small22[i];
  }
  cout<<""<<endl;
  small22.reserve(1);
  for(size_t i = 0; i < small22.size(); i++){
    cout<<small22[i];
  }
  cout<<""<<endl;

//Testing -= operator
string top = "150";
string top1 = "250";
string bottom = "50";

dbiguint topBig = dbiguint(top);
dbiguint bottomBig = dbiguint(bottom);

topBig-=bottomBig;
cout<< "(" << top << "- "<<bottomBig << ") = " << topBig<< endl;

//Testing - operator
dbiguint topBig2 = dbiguint(top1);
dbiguint bottomBig2 = dbiguint(bottom);

dbiguint subtracted = topBig2-bottomBig2;
cout<< "(" << topBig2 << "- " <<bottomBig2 << ") = " << subtracted << endl;
*/

/*
----------------------END OF PROBLEM 3------------------------------------------
*/

/*
----------------------START OF PROBLEM 4------------------------------------------
*/
/*
cout<<"--------Start of Problem 4--------"<<endl;
dbiguint mult1 = dbiguint(top);
dbiguint mult2 = dbiguint(bottom);
mult1*=mult2;
cout<< mult1<<endl;

//Testing just the * operator
dbiguint multTest = mult1*mult2;
cout<< mult1 << " times " << mult2 << " equals " << multTest<<endl;


  return 10000;
}
*/
/*
----------------------END OF PROBLEM 4------------------------------------------
*/
