#include <string>
#include <iostream>
using namespace std;

bool isSorted(int a[], int n);

int main(){
  int x[10] = {1,2,3,4,5,6,7,8,9,10};
  int notSorted[10] = {10,2,3,4,7,6,7,8,9,10};
  int notSorted2[10] = {1,2,3,4,7,6,7,8,9,10};
  if(isSorted(x, 10)){
    cout<< "Sorted" << endl;
  }
  else{
    cout<< "Is NOT Sorted" << endl;
  }

  if(isSorted(notSorted, 10)){
    cout<< "Sorted" << endl;
  }
  else{
    cout<< "Is NOT Sorted" << endl;
  }

  if(isSorted(notSorted2, 10)){
    cout<< "Sorted" << endl;
  }
  else{
    cout<< "Is NOT Sorted" << endl;
  }


	return 0;
}

bool isSorted(int a[], int n){
	if (n == 2){
    return(a[0] <= a[1]);

	}
  else{
    return(a[n-1] >= a[n-2] && isSorted(a, n-1));
  }

}
