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
			   //cout << "Swapping " << i << "," << j << endl;
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
	//cout << "Check the heap: " << endl;	
	
	//for (int k = 0; k < arraySize; k++) cout << array[k] << endl;	
	
	/*

		the heap is hereforth valid

	*/
	
	cout << "sort the heap" << endl;
	//sort heap
	int end = arraySize - 1;
	while (end > 0){
		swap(array[end], array[0]);
		end--;
		heapifyDown(array, 0, end);
	}	
		
	cout << "Check the 'sorted' array" << endl;
		
	for (int h = 0; h < arraySize; h++) cout << array[h] << endl;
	
	cout << "Sorted array" << endl;
			
	return;
}

bool verify(int array[], int arraySize){
	
	//for (int k = 0; k < arraySize - 1; k++){ cout << array[k] << endl; }
	
	for (int i = 0; i < arraySize - 1; i++){
		if(array[i] > array[i + 1]){
			cout << "The array was NOT sorted!" << endl;
			return false;
		}
	}
	cout << "The array was sorted!" << endl;
	return true;
}
