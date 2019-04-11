#include <iostream>
#include <string>
using namespace std;

template <typename T>
T abs (T a, T b);

int main(){
	double test1 = 15000.00;
	double test2 = 10093.03;

	int intTest1 = 15;
	int intTest2 = 10;

	int resultInt = abs(intTest1, intTest2);
	cout << "Result of int abs = " <<resultInt << endl;

	cout << "" << endl;

	double resultDouble = abs(test1, test2);
	cout<< "Result of double abs = " << resultDouble << endl;

}

template <typename T>
//Type variables must have the subtraction and greater than operations
T abs (T a, T b){
	T AminusB = a-b; 
	T BminusA = b-a;
	if(AminusB > BminusA){
		return AminusB;
	}
	else{
		return BminusA;
	}

}