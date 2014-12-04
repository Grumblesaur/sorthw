#include <iostream>
#include "helper.h"

using namespace std;

void bucketSort(int array[], int arraySize, int numBuckets){
	//numBuckets is passed in as the MOD value used on rand() in main
	
	//create a bucket for each possible value in the array
	int buckets[numBuckets];
	
	//empty all the buckets
	for (int i = 0; i < numBuckets; i++){
		buckets[i] = 0;
	}
	
	//for each int in the array
	for (int j = 0; j < arraySize; j++){
		//increment the bucket that holds the value found at index j of the array
		//e.g. if array[j] is 47, then buckets[47] is increased by one
		buckets[array[j]]++;
	}
	
	//create loop variables to avoid stepping outside the bounds of buckets[] and array[]
	int n = 0;
	int m = 0;
	while (n < numBuckets && m < arraySize){
		//for as many of each number is found in a bucket
		for (int k = buckets[n]; k > 0; k--){
			//put that number into its sorted place in the array
			array[m++] = n;
		}
		//move onto the next bucket
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
			return false;
		}
	}
	return true;
}
