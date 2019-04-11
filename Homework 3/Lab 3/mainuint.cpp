#include <iostream>
#include "biguint.h"

int main(){
  biguint test1 = biguint();
  std::string x = "120123";
  std::string y = "50";
  std::string z = "9234345";

  biguint test2 = biguint(x);
  std::string finishedProduct = test2.toString();
  std::cout << finishedProduct << std::endl;

}
