#include <iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> vect;
  ifstream inFile("gentleseduction.txt");   //For Gentle Seduction
  //ifstream inFile("don_quixote.txt");
  string word;
  while (inFile >> word){
    vect.push_back(word);
  }
  inFile.close();
  sort(vect.begin(), vect.end());

  ofstream outFile("outGS.txt");
  //ofstream outFile("DonQuixOut.txt");
  for(auto e:vect){
    outFile<<e<<endl;
  }
  outFile.close();

  //Deleting duplicates
  vector<string> vectNoDup;
  ifstream finalInFile("outGS.txt");
  ofstream finalOutFile("noDupsNumTimes.txt");   //For Gentle Seduction
  //ofstream finalOutFile("DonQuixOut2.txt");
  string wordIn;
  while (finalInFile >> wordIn){
    vectNoDup.push_back(wordIn);
  }
  finalInFile.close();
  size_t lengthOfVect = vectNoDup.size();
  size_t tempCount = 1;

  for(size_t i = 0; i < lengthOfVect; ++i){
    if(vectNoDup[i] == vectNoDup[i+1]){
      tempCount++;
    }

    else{
      finalOutFile<<vectNoDup[i] << "   Num Times Occurred: " << tempCount <<endl;
      tempCount = 1;
    }
  }

  finalOutFile.close();

  return 0;
}
