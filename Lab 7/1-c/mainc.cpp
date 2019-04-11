//c) A running list of everyone you served in 2016, in the order they were served (with duplicates).
#include <iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> peopleServed;
  ifstream inFile("lab4.txt");
  string line;
  while (getline(inFile, line)){
    peopleServed.push_back(line);
  }
  inFile.close();

  ofstream outFile("outputC.txt");
  for(auto e:peopleServed){
    outFile<<e;
  }

}
