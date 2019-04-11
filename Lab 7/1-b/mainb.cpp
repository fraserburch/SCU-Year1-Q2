//b) The name of each individual you served in 2016, and how many times you’d served that individual.
#include <iostream>
#include<fstream>
#include <string>
#include <map>
using namespace std;

int main(){
  map<string, int> peopleServed;
  ifstream inFile("lab4.txt");
  string line;
  while (getline(inFile, line)){
    peopleServed[line] += 1;
  }
  inFile.close();

  ofstream outFile("outputB.txt");
  string name;
  int numServed;
  for(auto e : peopleServed){
    outFile<<e.first<<e.second<<endl;
  }

  //Question a: how many times were you served?
  int numMealsServed = 0;
  for(auto e : peopleServed){
    numMealsServed+=e.second;
  }
  cout<< "We served " << numMealsServed << " meals" << endl;


  //Question c: Average number of times we served a person?
  double numPeople = (double)1.0*peopleServed.size();
  double numMeals = (double)1.0*numMealsServed;
  double avgServed = numMeals/numPeople;
  cout<< "We served an average of " << avgServed << " meals to a person." <<endl;

}
