#include "biguint.h"

biguint::biguint(){
  for(std::size_t i = 0; i < CAPACITY; i++){
    data_[i]=0;
  }
}

biguint::biguint(const std::string &a){
  int j = 0;
  char zero = '0';
  int codeZero = zero;
  for(std::size_t i = 1; i < a.size()+1; i++){
    int tempNum = a[a.length() - i];
    int numCode = tempNum - codeZero;
    data_[j]=numCode;
    j++;
  }
  if(j < CAPACITY){
    for(int x = j; x < CAPACITY; x++){
      data_[x]=0;
    }
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  return biguint::data_[pos];
}

std::ostream& operator <<(std::ostream& out, biguint b){
  for(size_t i = 0; i < biguint::CAPACITY; i++){
    out << b[i] << " ";
  }
  out << std::endl;
  return out;
}

void biguint::operator +=(const biguint & b){
  for(int i = 0; i < CAPACITY; i ++){
    data_[i] = data_[i]+b.data_[i];
  }
}


// pre: none
// post: returns 1 if this biguint > b
//               0 if this biguint == b
//              -1 if this biguint < b
int biguint::compare(const biguint & b) const{
  int lhsIdx = 0;
  int rhsIdx = 0;
  while(data_[CAPACITY - 1 - lhsIdx] == 0){
    lhsIdx++;
  }
  while(b.data_[CAPACITY - 1 - rhsIdx] == 0){
    rhsIdx++;
  }
  if(lhsIdx > rhsIdx){return -1;}
  else if(lhsIdx < rhsIdx){return 1;}
  else if(lhsIdx == rhsIdx){
    for(int i = 0; i < CAPACITY - lhsIdx; i++){
      if(data_[lhsIdx - i] > b.data_[rhsIdx - i]){return 1; break;}
      if(data_[lhsIdx - i] < b.data_[rhsIdx - i]){return -1; break;}
    }
  }
  return 0;
}

//Problem 2


bool operator < (const biguint &b1, const biguint &b2){
  if(b1.compare(b2) == -1){
    return true;
  }
  return false;
}

bool operator <= (const biguint &b1, const biguint &b2){
  if(b1.compare(b2) == -1 || b1.compare(b2) == 0){
    return true;
  }
  return false;
}

bool operator != (const biguint &b1, const biguint &b2){
    if(b1.compare(b2) != 0){
      return true;
    }
    return false;
}

bool operator == (const biguint &b1, const biguint &b2){
    if(b1.compare(b2) == 0){
      return true;
    }
    return false;

}

bool operator >= (const biguint &b1, const biguint &b2){
  if(b1.compare(b2) == 1 || b1.compare(b2) == 0){
    return true;
  }
  return false;
}

bool operator > (const biguint &b1, const biguint &b2){
  if(b1.compare(b2) == 1){
    return true;
  }
  return false;
}

//Problem 3
void biguint::operator -= (const biguint & b){
  //assert(data_[CAPACITY-1] < b.data_[CAPACITY-1]);

  for(size_t i = 0; i <= CAPACITY; i++){
    if(data_[i] > b.data_[i]){
      data_[i] = data_[i] - b.data_[i];
    }
    else if(data_[i] < b.data_[i]){
      int tempHolder = data_[i] + 10;
      tempHolder = tempHolder - b.data_[i];
      data_[i+1] = data_[i+1] - 1;
      data_[i] = tempHolder;
    }
  }
}

biguint operator - (const biguint &b1, const biguint &b2){
  biguint toReturnBU;
  toReturnBU += b1;
  toReturnBU -= b2;
  return toReturnBU;
}

//Problem 4
std::string biguint::toString() const{
  int decimalCounter = 1;
  int numHolder = 0;
  int initialBoot = 0;
  int strCount = 0;
  int arrOfInt[20];

  for(size_t i = CAPACITY-1; i > 0; i--){
    if(data_[i] == 0 && initialBoot == 0){}
    else{
      initialBoot = 1;
      arrOfInt[strCount] = data_[i];
      numHolder += data_[i]*decimalCounter;
      decimalCounter = decimalCounter*10;
      strCount++;
    }
  }
  arrOfInt[strCount] = data_[0];
  char arrOfChar[strCount];
  for(int i = 0; i <= strCount; i++){
    arrOfChar[i] = '0'+ arrOfInt[i];
  }
    char tempHolder;
    std::string str;
  for(int i = 0; i <= strCount; i++){
    tempHolder = arrOfChar[i];
    str += tempHolder;
  }
  return str;
}
