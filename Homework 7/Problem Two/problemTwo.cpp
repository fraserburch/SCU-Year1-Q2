#include <iostream>
#include<fstream>
#include <string>
#include <set>
using namespace std;

int main(){
  set<string> setOfWords;
  //ifstream inFile("gentleseduction.txt");   //For Gentle Seduction
  ifstream inFile("don_quixote.txt");
  string word;
  while (inFile >> word){
    setOfWords.insert(word);
  }
  inFile.close();
  //ofstream outFile("outGS.txt");    //For Gentle Seduction
  ofstream outFile("outDQ.txt");
  for(auto e:setOfWords){
    outFile<<e<<endl;
  }
  outFile.close();
  return 0;
}
