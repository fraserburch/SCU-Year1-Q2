#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
T1 frequent (T1 a[], T2 size);

int main(){

	int intArr[10] = {1,8,8,4,5,6,7,8,9,10};
	int mostFreqInt = frequent(intArr, 10);
	cout << mostFreqInt << endl;

	string stringArr[8] = {"WHOA","Hey","Hey","Hey","hi","Hey","Hey","Hey"};
	string mostFrequentString = frequent(stringArr, 8);
	cout << mostFrequentString << endl;


return 0;
}

template <typename T1, typename T2>
//T1 must
//T2 must have + operator, = operator, 
T1 frequent (T1 a[], T2 size){
	T2 hitTemp = 0;
	T2 hitMax = 0;
	T2 maxIndex = 0;
	int itsFirst = 0;
	for(T2 i = 0; i < size-1; i++){
		for(T2 j = 0; j < size; j++){
			if(a[i] == a[j]){
				if(itsFirst != 0){
					hitTemp++;
				}
				else{
					hitMax++;
				}

				if(hitTemp > hitMax){
					hitMax = hitTemp;
					maxIndex = i;
				}
			}
		}
		itsFirst = 1;
		hitTemp = 0;
	}

	return(a[maxIndex]);
}