
#include "Rational.h"

Rational::Rational(int n, int d){
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}



Rational Rational::operator +(Rational b){//Full function definition after main
  Rational ans;//:: is the scope operator, changes the scope of the thing we're defining
  ans.numer_ = (numer_*b.denom_+b.numer_*denom_);
  ans.denom_ = (denom_*b.denom_);
  return ans;
}
Rational Rational::operator *(Rational b){
    Rational ans;//Rational:: goes before the name of the thing whose scope you're changing
    ans.numer_ = (numer_*b.numer_);
    ans.denom_ = (denom_*b.denom_);
    return ans;
}

bool operator == (Rational lhs, Rational rhs){
  int lNum = lhs.numer();
  int rDenom = rhs.denom();
  int rNum = rhs.numer();
  int lDenom = lhs.denom();
  int divideBy;
  int newNum;
  int newDenom;

  if(lDenom == rDenom && lNum == rNum){
    return true;
  }

  else if (lDenom > rDenom){
    if (lDenom%rDenom == 0){
      divideBy = lDenom/rDenom;
      newNum = lNum/divideBy;
      newDenom = lDenom/divideBy;

      if(newDenom == rDenom && newNum == rNum){
        return true;
      }
    }
  }

    else if (rDenom > lDenom){
      if (rDenom%lDenom == 0){
        divideBy = rDenom/lDenom;
        newNum = rNum/divideBy;
        newDenom = rDenom/divideBy;

        if(newDenom == lDenom && newNum == lNum){
          return true;
        }
      }
    }
      return false;
    }

    void Rational::operator +=(Rational rhs){
      int tmpDenom = rhs.denom()*denom_;
      int tmpNumerator = (rhs.numer()*denom_)+(rhs.denom()*numer_);
      numer_ = tmpNumerator;
      denom_ = tmpDenom;
    }

    void Rational::reduce(){
      int tmpNumer = numer_;
      int tmpDenom = denom_;
      int gCd;
      //computing GCD
      while (tmpNumer != 0 && tmpDenom != 0){
        if(tmpNumer > tmpDenom){
          tmpNumer = tmpNumer%tmpDenom;
        }
        else{
          tmpDenom = tmpDenom%tmpNumer;
        }
      }
      if(tmpDenom > tmpNumer){
        numer_ = numer_/tmpDenom;
        denom_ = denom_/tmpDenom;
      }
      else{
        denom_ = denom_/tmpNumer;
        numer_ = numer_/tmpNumer;
      }
      //numer_ = tmpNumer;
    //  denom_ = tmpDenom;

    }
