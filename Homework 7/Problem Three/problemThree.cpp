#include <iostream>
#include<fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

int stringToInt(string a);
int countNumScores(int scorePassed);
multiset<int> sortedScores;
void printMap(map<int, pair<int,vector<string> > > tempMap);
int finalScore = 0;

int main(){

  //The first int is the score.
  //The second int is how many people got that score.
  //The vector of strings is a list of everyone who got that score.
  map<int, pair<int,vector<string> > > myBigMap;

  //Reading in from file
  ifstream inFile("scorename.txt");
  string word;
  int initialBoot = 0;
  string number;
  string name;
  int countOfScore;
  map<int, vector<string>> preMap;
  while (getline(inFile, word)){
      while(word[initialBoot] != ' '){
        initialBoot++;
      }
      number = word.substr(0,initialBoot);
      name = word.substr(initialBoot+1, word.size());
      int numInInt = stringToInt(number);
      preMap[numInInt].push_back(name);//Filling Pre Vector with the score and the names of the people who got that score

      //Filling the num people who got the score
      initialBoot = 0;
  }

  //Making Pairs from preMap
  vector<string> tempNameHolder;
  int numScores = 0;
  for(auto e: preMap){
    for(int i = 0; i < e.second.size(); i++){
      numScores++;
      tempNameHolder.push_back(e.second[i]); // Adds Name to Vector
    }
    pair<int,vector<string>> tempPair;
    tempPair.first = e.second.size();
    tempPair.second = tempNameHolder;
    myBigMap[e.first] = tempPair;
    tempNameHolder.erase(tempNameHolder.begin(), tempNameHolder.end());
  }



  int countToStop = 0;
  //FOR PRINTING THE SCORES
  for(auto e: myBigMap){
    while(countToStop != e.first){
      cout<<countToStop<<endl;
      countToStop++;
    }
    cout<<countToStop;
    for(int i = 0; i < e.second.first; i++){
      cout<<"X";
    }
    cout<<endl;
    countToStop++;
  }
  //DONE PRINTING SCORES

  //FOR ASKING USER IF THEY WANT TO PRINT NAMES FOR GIVEN SCORE
  cout<<""<<endl;
  cout<<"Enter a score to see the people who received that score."<<endl;
  int scoreToSee;
  cin >> scoreToSee;
  for(auto e : myBigMap){
    if(e.first == scoreToSee){
      for(int i = 0; i < e.second.first; i++){
        cout<<e.second.second[i] <<  endl;
      }
    }
  }



  return 0;
}


//For converting the text file score string to an int
int stringToInt(string a){
  char zero = '0';
  int codeZero = zero;
  int tempNum;
  int numCode = 0;
  for(std::size_t i = 0; i < a.size(); ++i){
    tempNum = a[i];
    if(tempNum - codeZero == 0){
      numCode = numCode*10;
    }
    else{
      numCode += tempNum - codeZero;
    }
  }
  sortedScores.insert(numCode);
  return numCode;
}


//For counting number of each score
int countNumScores(int scorePassed){
  int counter = 0;
  for(auto e : sortedScores){
    if(e == scorePassed){
      counter++;
    }
    finalScore = e;
  }
  return counter;

}
