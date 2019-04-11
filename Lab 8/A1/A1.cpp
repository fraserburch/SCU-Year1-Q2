#include <string>
#include <iostream>
using namespace std;

double water(int n);

int main(){
	double waterLeft = water(5);
	cout<< waterLeft << endl;

	return 0;
}

double water(int n){
	if (n == 0){
		return(10);

	}
	return(water(n-1)/2.0+1.0);

}
