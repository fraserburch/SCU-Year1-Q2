#include <iostream>
#include <string>
#include "class.h"
using namespace std;

int main(){

  Movie myMovie = Movie("FIRST MOVIE", "PG-13", 1);
  Movie oneMovie = Movie("FIRST MOVIE", "R", 2);

  cout << myMovie.getName() << endl;
  Movie combinedMovie = myMovie.mergeMovie(oneMovie);
  cout << combinedMovie.getName() << endl;
  cout << combinedMovie.getRating() << endl;
  cout << combinedMovie.getGross() << endl;



};
