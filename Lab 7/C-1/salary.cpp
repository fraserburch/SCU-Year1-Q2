#include <iostream>
#include <string>
using namespace std;

int salary(int n);
int main(){
int afterTwo = salary(2);
cout<< afterTwo <<endl;



return 0;
}

int salary(int n){
  if (n == 0 ){
    return 50000;
  }
  else{
   return (5000+1.1*salary(n-1));
  }
}
