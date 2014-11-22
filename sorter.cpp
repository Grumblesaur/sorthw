#include <iostream>
#include <cstdlib>
#include <ctime>
#include "helper.h"
#include "algorithm.h"

using namespace std;

int main(int argc, char *argv[]){
	
	string arraySizeException = "Invalid array size! \n";
	string sortAlgorithmException = "Invalid algorithm! \n";
	
	//throw exception if there's no size given to create the array
	if (argv[2] == ""){
		throw arraySizeException;
	}

	//throw exception if array size is 0
	if (argv[2] == "0"){
		throw arraySizeException;
	}
	
	//throw exception if array size is passed as negative
	if (argv[2][0] == '-'){
		throw arraySizeException;
	}
	
	//throw exception if incorrect algorithm argument is given
	if (argv[1] != "bucket" || "bubble" || "heap"){
		throw sortAlgorithmException;
	}

	//convert c-string to int for arraySize
	int arraySize = atoi(argv[2]);

	//instantiate an array of that size
	int array[arraySize];
	
	//seed RNG
	srand(time(0));
	
	//fill array with integers in 0-999999 range
	for (int i = 0; i < arraySize; i++){
		array[i] = rand() % 1000000;
	}

	if (argv[1] == "bucket"){
		bucketSort(array, arraySize);
	} else if (argv[1] == "bubble"){
		bubbleSort(array, arraySize);
	} else if (argv[1] == "heap"){
		heapSort(array, arraySize);
	}

	verify(array, arraySize);

	return 0;
}
