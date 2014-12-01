#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include "algorithm.h"

using namespace std;

 //declare value for mod value on rand()
const int MOD = 1000000;

//declare some exceptions for use below
const string arraySizeException = "Invalid array size!";
const string sortAlgorithmException = "Invalid algorithm!";
const string argcException = "Invalid number of arguments!";



int main(int argc, char *argv[]){
	
	//throw exception if there's no size given to create the array
	if (argc < 3){
		cout << argcException << endl;
		exit(1);
	} else if (argc > 3){
		cout << "NOTE: Arguments beyond array size will be ignored!" << endl;
		cout << "Press 'enter' to continue." << endl;
		cin.get();
	}
	
	string algorithmName(argv[1]);
	
	//throw an exception if user enters an unimplemented algorithm name
	if ((algorithmName != "bubble") && (algorithmName != "bucket") 
		                        && (algorithmName != "heap")){
		cout << sortAlgorithmException << endl;
		exit(2);
	}
	
	//convert c-string to int for arraySize
	int arraySize = atoi(argv[2]);

	//ensure that arraySize is safe, or throw an exception
	if (arraySize == 0){
		cout << "Cannot create a zero-element array!" << endl;
		exit(3);
	}
	
	else if (arraySize < 0){
		cout << "Cannot create an negatively-sized array!" << endl;
		exit(3);
	}
	
	
	/*

		all inputs are hereforth safe to use

	*/
	
	//instantiate an array of that size
	int array[arraySize];
	
	//seed RNG
	srand(time(0));
	
	//fill array with integers in 0-999999 range
	for (int i = 0; i < arraySize; i++){
		array[i] = rand() % MOD;
	}

	if (algorithmName == "bucket"){
		bucketSort(array, arraySize, MOD);
	} else if (algorithmName == "bubble"){
		bubbleSort(array, arraySize);
	} else if (algorithmName == "heap"){
		heapSort(array, arraySize);
	}

	verify(array, arraySize);

	return 0;
}
