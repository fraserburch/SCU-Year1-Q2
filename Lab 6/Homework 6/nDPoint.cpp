#include "nDPoint.h"

int operator - (const std::string& a1, const std::string& a2){
   int encodingDif = a1[0] - a2[0];
   return encodingDif;
}
