#include "dbiguint.h"
#include <iostream>

dbiguint::dbiguint(){
  data_ = new unsigned short[1];
  data_[0] = 0;
  capacity_ = 1;
}

dbiguint::dbiguint(const std::string &a){
  data_ = new unsigned short[a.size()];
  capacity_ = a.size();
  int j = 0;
  char zero = '0';
  int codeZero = zero;
  for(std::size_t i = 1; i < a.size()+1; i++){
    int tempNum = a[a.length() - i];
    int numCode = tempNum - codeZero;
    data_[j]=numCode;
    j++;
  }
}


std::size_t dbiguint::size() const{
  return capacity_;
}


unsigned short dbiguint::operator [](std::size_t pos) const{
  if (pos < capacity_){return dbiguint::data_[pos];}
  else{return 0;}
}

std::ostream& operator <<(std::ostream &out, const dbiguint &b){
  for(size_t i = b.size()-1; i >0; i--){
      //std::cout<<i<<std::endl;
    out<<b[i]<<" ";
  }
  out<<b[0]<<" ";
  //out << std::endl;
  return out;
}

  void dbiguint::reserve(std::size_t newcapacity_){
    //For increasing size
    if(newcapacity_ > capacity_){
      unsigned short * tempData_ = new unsigned short[newcapacity_];
      for (size_t i = 0; i < capacity_; i++){
        tempData_[i] = data_[i];
      }
        for(size_t j = capacity_; j < newcapacity_; j++){
          tempData_[j] = 0;
        }
        capacity_ = newcapacity_;
      delete [] data_;
      data_ = tempData_;
      tempData_ = nullptr;
    }
    //For decreasing size
    else if(newcapacity_ < capacity_){
      size_t initialBootOut = 0;
      size_t leadingZeros = 0;
      for(size_t i = (capacity_-1); i >0; i--){
        if(data_[i] == 0 && initialBootOut == 0){
          leadingZeros++;
        }
        else{
          initialBootOut = 1;
        }
      }
      size_t newCap = capacity_-leadingZeros;
      unsigned short * tempData2_ = new unsigned short[newCap];
      for(size_t j = 0; j < newCap; j++){
        tempData2_[j] = data_[j];
      }
      capacity_ = newCap;
      delete [] data_;
      data_ = tempData2_;
      tempData2_ = nullptr;
    }
  }



void dbiguint::operator +=(const dbiguint & b){
  if(b.size() > capacity_){
    reserve(b.size());
  }
  else{
    reserve(capacity_);
  }
  for(size_t i = 0; i < capacity_; i++){
    if (data_[i] + b.data_[i] > 9){

      data_[i+1] = data_[i+1] + 1;
      int tempHolder = data_[i] + b.data_[i];
      tempHolder = tempHolder%10;
      data_[i] = tempHolder;
    }
    else{
      data_[i] = (data_[i] + b.data_[i]);
    }
    }
}


                                      /*
--------------------------------------------------------------------------------
                      PROBLEM 2 - Steps 5 - 7 from Lab 4
                                      */
dbiguint:: ~dbiguint(){
  delete [] data_;//This is the only piece we NEED
  data_ = nullptr;
  capacity_ = 0;
}

int dbiguint::compare(const dbiguint & b) const{
  int initialBoot = 0;
  int initialBoot2 = 0;
  size_t numDigits = 0;
  size_t bNumDigits = 0;
  int toReturn = 0;

  //For class within dbiguint
  for(size_t i = capacity_-1; i > 0; i--){
    if(data_[i] == 0 && initialBoot == 0){numDigits++;}
    else{
        initialBoot = 1;
    }
  }

  //For parameter dbiguint
  for(size_t i = b.size()-1; i > 0; i--){
    if(b[i] == 0 && initialBoot2 == 0){bNumDigits++;}
    else{
        initialBoot2 = 1;
    }
  }

  size_t numTrueDigits = capacity_ - numDigits;
  size_t bnumTrueDigits = b.capacity_ - bNumDigits;
  if (numTrueDigits < bnumTrueDigits){ //If parameter has more true digits
    toReturn = -1;
  }
  else if (numTrueDigits > bnumTrueDigits){ //If parameter has more true digits
    toReturn = 1;
  }

  else{ //if number of true digits match
    for(size_t i = b.size()-1; i >= 1; i--){
    if(data_[i] > b[i]){

      toReturn = 1;
      break;
    }
    else if(data_[i] < b[i]){
      toReturn = -1;
      break;
      }
      else{
        toReturn = 0;
      }
    }
  }
  return (toReturn);
}

dbiguint operator +(const dbiguint &b1, const dbiguint &b2){

  dbiguint tempBigUInt;
   tempBigUInt += b1;
   tempBigUInt += b2;
   return tempBigUInt;
}

bool operator < (const dbiguint &b1, const dbiguint &b2){
  if(b1.compare(b2) == -1){
    return true;
  }
  return false;
}

bool operator <= (const dbiguint &b1, const dbiguint &b2){
  if(b1.compare(b2) == -1 || b1.compare(b2) == 0){
    return true;
  }
  return false;
}

bool operator == (const dbiguint &b1, const dbiguint &b2){
  if(b1.compare(b2) == 0){
    return true;
  }
  return false;
}

bool operator != (const dbiguint &b1, const dbiguint &b2){
  if(b1.compare(b2) != 0){
    return true;
  }
  return false;
}

bool operator >= (const dbiguint &b1, const dbiguint &b2){
  if(b1.compare(b2) == 1 || b1.compare(b2) == 0){
    return true;
  }
  return false;
}

bool operator > (const dbiguint &b1, const dbiguint &b2){
  if(b1.compare(b2) == 1){
    return true;
  }
  return false;
}

//Copy constructor
dbiguint::dbiguint(const dbiguint &b){
  data_ = new unsigned short[b.size()];
  capacity_ = b.size();
  for(std::size_t i = 0; i < b.size(); i++){
    data_[i]=b[i];
  }
}

//Overloaded = operator to return a DBIGUINT
dbiguint dbiguint::operator =(const dbiguint &b){
  dbiguint toReturn = dbiguint(b);
  return(toReturn);
}
                                    /*
--------------------------------------------------------------------------------
                          END OF PROBLEM 2
                                    */

                                    /*
--------------------------------------------------------------------------------
                          START OF PROBLEM 3
                                    */


dbiguint dbiguint::operator -= (const dbiguint & b){
  reserve(1);
  for(size_t i = 0; i < capacity_; i++){
    if(data_[i] > b[i]){
      data_[i] = (data_[i] - b[i]);
    }
    else if(data_[i] < b[i]){
      int tempHolder = data_[i] + 10;
      tempHolder = tempHolder - b[i];
      data_[i+1] = data_[i+1]-1;
      data_[i] = tempHolder;
    }
    else{
      data_[i] = 0;
    }
  }
  reserve(1);
  return(*this);
}

dbiguint operator -(const dbiguint &b1, const dbiguint &b2){
  dbiguint newTemp = dbiguint(b1);
  newTemp-= b2;
  return(newTemp);
}
                                          /*
--------------------------------------------------------------------------------
                                    END OF PROBLEM 3
                                          */

                                          /*
--------------------------------------------------------------------------------
                                    START OF PROBLEM 4
                                          */

dbiguint dbiguint::operator *=(const dbiguint & b){
  //b.reserve(1);
  size_t firstBigInt = 0;
  size_t secondBigInt = 0;
  size_t tensSpot = 1;
  dbiguint newTemp;

  for(size_t i = 0; i < capacity_; i++){
    firstBigInt += data_[i]*tensSpot;
    tensSpot = tensSpot*10;
  }
  tensSpot = 1;
  for(size_t i = 0; i < b.size(); i++){
    secondBigInt += b[i]*tensSpot;
    tensSpot = tensSpot*10;
  }

  size_t holder = secondBigInt*firstBigInt;
  size_t digitCount = 10;
  size_t numDigitsHolder = 1;
  while((holder % digitCount) != holder){
    digitCount = digitCount*10;
    numDigitsHolder++;
  }
  size_t modBy = 10;
  size_t divideBy = 1;
  int hit = 0;
  reserve(numDigitsHolder);
  for(size_t i = 0; i < numDigitsHolder; i++){
    data_[i] = (holder % modBy)/divideBy;
    modBy = modBy *10;
    divideBy = divideBy*10;
  }
  return (*this);
}

dbiguint operator *(const dbiguint &b1, const dbiguint &b2){
  dbiguint toReturn = dbiguint(b1);
  toReturn*=b2;
  return toReturn;
}

std::istream & operator >> (std::istream &in, dbiguint &b){
  std::cout << "Enter a number " << std::endl;
  std::string tempHolder;
  in >> tempHolder;
  std::cout<<""<<std::endl;
  std::cout<< "You entered: " << tempHolder << std::endl;
  dbiguint tempBigInt = dbiguint(tempHolder);
  b += tempBigInt;
  return in;
}




                                      /*
--------------------------------------------------------------------------------
                                END OF PROBLEM 4
                                      */
