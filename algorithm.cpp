#include <iostream>
#include "helper.h"

using namespace std;

void bucketSort(int array[], int arraySize){

	//finish this code
	return;

}

void bubbleSort(int array[], int arraySize){

	for (int i = 0; i < arraySize - 1; i++){
		for (int j = 0; j < arraySize - i - 1; j++){
			if (array[j] > array[j + 1]){
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void heapSort(int array[], int arraySize){

	//finish this code
	return;
}

void verify(int array[], int arraySize){

	for (int i = 0; i < arraySize - 1; i++){
		if(array[i] > array[i + 1]){
			cout << "The array was NOT sorted!" << endl;
			return;
		}
	}
	cout << "The array was sorted!" << endl;
}
