#include <iostream>
#include "helper.h"

using namespace std;

void bucketSort(int array[], int arraySize, int numBuckets){
	int buckets[numBuckets];
	
	for (int i = 0; i < numBuckets; i++){
		buckets[i] = 0;
	}
	
	for (int j = 0; j < arraySize; j++){
		buckets[array[j]]++;
	}
	
	int n = 0;
	int m = 0;
	while (n < numBuckets && m < arraySize){
		for (int k = buckets[n]; k > 0; k--){
			array[m++] = n;
		}
		n++;
	}	
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
	
	//create heap	
	for (int i = 0; i < arraySize; i++){
		heapifyUp(array, i);		
	}
	//sort heap
	int end = arraySize - 1;
	while (end > 0){
		swap(array[end], array[0]);
		end--;
		heapifyDown(array, 0, end);
	}	
			
	return;
}

bool verify(int array[], int arraySize){
	for (int i = 0; i < arraySize - 1; i++){
		if(array[i] > array[i + 1]){
			cout << "The array was NOT sorted!" << endl;
			return false;
		}
	}
	cout << "The array was sorted!" << endl;
	return true;
}
