#include "ATM.h"
#include "bankaccount.h"

ATM::ATM(){
  tens = 0;
  twenties = 0;
}


ATM::ATM(int numTens, int numTwenties){
  tens = numTens;
  twenties = numTwenties;
}

BankAccount ATM::get_cash(int amount, BankAccount b){
  int atmTotalMoney = twenties*20 + tens*10;
  if(amount > b.get_balance()){
    std::cout <<"Your balance is " << b.get_balance() << " you have insufficient funds."<<std::endl;
  }

  else if(atmTotalMoney < amount){
    std::cout << "The ATM is low on money and can not let you withdraw, We're sorry!"<<std::endl;
  }

  else{
    int numTwenties = (amount/20);
    int numTens = (amount%20)/10;

    std::cout << "You will receive " << numTwenties << " twenty dollar bills and " << numTens << " ten dollar bills. Thank you!" << std::endl;

    b.withdraw(amount);
  }
  return b;
}

void operator +=(ATM& rhs){
  tens = tens + rhs.getTens();
  twenties = twenties + rhs.getTwenties();
}

void restock(int new20s, int new10s){
  twenties = twenties + new20s;
  tens = tens + new10s;
}

bool operator ==(ATM lhs, ATM rhs){ //returns true if the two ATMS contain same amoutn of $
  if (lhs.getTens() == rhs.getTens() && lhs.getTwenties() == rhs.getTwenties()){return true;}
  else{return false;}
}
std::ostream& operator <<(std::osteam& out, ATM a){ // Prints out info about a in a sensible format
  std::cout<<"Number of twenties: " << ATM::a.getTwenties() <<endl;
  std::cout<<"Number of tens: " << ATM::a.getTens() <<endl;
  int totalAmount = a.getTwenties()*20 + a.getTens()*10;
  std::cout<<"Total amount in ATM: " << totalAmount <<endl;
}
