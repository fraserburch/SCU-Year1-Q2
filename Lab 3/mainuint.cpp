#include <iostream>
#include "biguint.h"

int main(){
  biguint test1 = biguint();
  std::string x = "12345";
  biguint test2 = biguint(x);
  biguint test3 = biguint(x);
  biguint test4 = biguint(x);
  biguint test5 = biguint(x);

  test3 += test2;
  size_t temp = 4;
  int fourthDigit = test2[temp];
  int testCompare = test1.compare(test4);
  int testCompare1 = test4.compare(test1);
  int testCompare2 = test4.compare(test5);

  std::cout << fourthDigit << std::endl;
  std::cout << test2;
  std::cout << test3;
  std::cout << testCompare << std::endl;
  std::cout << testCompare1 << std::endl;
  std::cout << testCompare2 << std::endl;
}
