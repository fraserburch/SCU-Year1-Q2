#include <iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> vect;
  ifstream inFile("gentleseduction.txt"); // for Gentle Seduction
  //ifstream inFile("don_quixote.txt");
  string word;
  while (inFile >> word){
    vect.push_back(word);
  }
  inFile.close();
  sort(vect.begin(), vect.end());

  ofstream outFile("outGS.txt");
  for(auto e:vect){
    outFile<<e<<endl;
  }
  outFile.close();

  //Deleting duplicates
  vector<string> vectNoDup;
  ifstream finalInFile("outGS.txt");
  ofstream finalOutFile("outFinalGS.txt"); // for Gentle Seduction
  //ofstream finalOutFile("outFinalDonQuixote.txt");
  string wordIn;
  while (finalInFile >> wordIn){
    vectNoDup.push_back(wordIn);
  }
  finalInFile.close();
  size_t lengthOfVect = vectNoDup.size();
  for(size_t i = 0; i < lengthOfVect; ++i){
    if(vectNoDup[i] != vectNoDup[i+1]){
      finalOutFile<<vectNoDup[i] <<endl;
    }
  }

  finalOutFile.close();

  return 0;
}
