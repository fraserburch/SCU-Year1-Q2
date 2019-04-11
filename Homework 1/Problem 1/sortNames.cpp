#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream inputFile("inputFile.txt");
//string unsortedArray;
int numPeople;
int numberOfNames();
void fillArray(string tempArr[]);
void printArray(string tempArr[]);
void sortArray(string tempArr[], string sortedTempArr[]);
void writeFile(string tempArr[]);



int main(){
  string unsortedArray[numberOfNames()]; //Creates an empty array based on number of people in file
  fillArray(unsortedArray); //Fills an array with people from file (not sorted)
  //printArray(unsortedArray);
  string sortedArray[numPeople]; //Creates an empty array based on number of people in file
  sortArray(unsortedArray, sortedArray);//Sorts the 'unsortedArray' array, and fills the 'sortedArray'
  writeFile(sortedArray);

  return(0);
}

//Counts how many names are in a text file
int numberOfNames(){
    int count = 0;
    string line;
    //ifstream file("inputFile.txt");
    while (getline(inputFile, line)){
      count++;
    }
    inputFile.close();
    //cout << "Numbers of names: " << count << endl;
    numPeople = count;
    return count;
}


void fillArray(string tempArr[]){
  //cout << "Starting fillArray" << endl;
  ifstream inFile("inputFile.txt");
  string line;
  int counter = 0;
  while (getline(inFile, line)){
    //cout << line << endl;
    tempArr[counter] = line;
    counter++;
  }
  inFile.close();
}


void sortArray(string tempArr[], string sortedTempArr[]){
  string firstName;
  string secondName;
  string tempStr;
  int first;
  int second;

  for (int i = 0; i < numPeople-1; i++){
    for (int j = i+1; j < numPeople; j++){
      if(tempArr[i].at(0) > tempArr[j].at(0)){
        tempStr = tempArr[i];
        tempArr[i] = tempArr[j];
        tempArr[j] = tempStr;
      }
    }
  }
  //cout << "Array after changing" << endl;
  for (int i = 0; i < numPeople; i++){
    sortedTempArr[i] = tempArr[i];
  }
  //printArray(tempArr);
}

void writeFile(string tempArr[]){
  ofstream outFile("outputFile.txt");
  for (int i = 0; i < numPeople; i++){
    outFile << tempArr[i] << endl;
  }
}


//Used for debugging and checking the array is printed properly
void printArray(string tempArr[]){
  for (int i = 0; i < numPeople; i++){
    cout << tempArr[i] << endl;
  }
}
