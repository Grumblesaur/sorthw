#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include "helper.h"
#include "algorithm.h"

using namespace std;

int main(int argc, char *argv[]){
	
	string arraySizeException = "Invalid array size!";
	string sortAlgorithmException = "Invalid algorithm!";
	string argcException = "Invalid number of arguments!";

	//cout << "Name of algorithm passed is: \"" << argv[1] << "\"" << endl;
	
	string algorithmName(argv[1]);

	//cout << "Converted to string object: \"" << algorithmName << "\"" << endl;
	
	//throw exception if there's no size given to create the array
	if (argc != 3){
		cout << "Improper number of arguments!" << endl;
		throw argcException;
	}
	
	//convert c-string to int for arraySize
	int arraySize = atoi(argv[2]);

	if (arraySize == 0){
		cout << "Cannot create a zero-element array!" << endl;
		throw arraySizeException;
	} else if (arraySize < 0){
		cout << "Cannot create an negatively-sized array!" << endl;
		throw arraySizeException;
	}
	
	
	//instantiate an array of that size
	int array[arraySize];
	
	//seed RNG
	srand(time(0));
	
	//fill array with integers in 0-999999 range
	for (int i = 0; i < arraySize; i++){
		array[i] = rand() % 1000000;
	}

	if (algorithmName == "bucket"){
		bucketSort(array, arraySize);
	} else if (algorithmName == "bubble"){
		bubbleSort(array, arraySize);
	} else if (algorithmName == "heap"){
		heapSort(array, arraySize);
	} else {
		cout << sortAlgorithmException << endl;
		throw sortAlgorithmException;
	}

	verify(array, arraySize);

	return 0;
}
