#include <iostream>
#include "bankaccount.h"

class ATM{
private:
  int twenties, tens;


public:
  ATM();
  ATM(int numTens, int numTwenties);

  BankAccount get_cash(int amount, BankAccount b);

  void operator +=(ATM& rhs);

  void restock(int new20s, int new10s);


int getTens(){
  return tens;
}

int getTwenties(){
  return twenties;
}

};

bool operator ==(ATM lhs, ATM rhs); //returns true if the two ATMS contain same amoutn of $
std::ostream& operator <<(std::ostream& out, ATM a); // Prints out info about a in a sensible format
