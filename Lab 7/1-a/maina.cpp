//a) The names of everyone you served in 2016 (no duplicates).
#include <iostream>
#include<fstream>
#include <string>
#include <unordered_set>
using namespace std;


int main(){
  unordered_set<string> peopleServed;
  ifstream inFile("lab4.txt");
  string line;
  while (getline(inFile, line)){
    peopleServed.insert(line);
  }
  inFile.close();

  ofstream outFile("outputA.txt");
  for(auto e:peopleServed){
    outFile<<e;
  }

  //Question b: how many different people did you serve?
  cout<< "We served " << peopleServed.size() << " different people." <<endl;

}
