#include <iostream>

using namespace std;

void swap(int & x, int & y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int leftChildIndex(int index){
        return (2 * index) + 1;
}

int rightChildIndex(int index){
        return (2 * index) + 2;
}

int parentIndex(int index){
	return ((index - 1) / 2);
}

bool hasLeftChild(int index, int arraySize){
	if (leftChildIndex(index) < arraySize){
		return true;
	}
	return false;
}

bool hasRightChild(int index, int arraySize){
	if (rightChildIndex(index) < arraySize){
		return true;
	}
	return false;
}

bool hasParent(int index){
	if (index == 0){
		return false;
	}
	return true;
}

void heapifyUp(int array[], int index){	
	while (hasParent(index)){
		//if the current element is greater than its parent
		if (array[index] > array[parentIndex(index)]){
			//swap the elements
			swap(array[index], array[parentIndex(index)]);
			//prepare to continue heapification from next element up
			index = parentIndex(index);
		} else {
			return;
		}
	}
	return;
}

void heapifyDown(int array[], int end){
	int root = 0;
	
	while(hasLeftChild(root, end + 1)){
		int swapv = root;
		int child = leftChildIndex(swapv);
		if (array[swapv] < array[child]){
			swapv = leftChildIndex(swapv);
		}
		if (child + 1 <= end && array[swapv] < array[child + 1]){
			swapv = child + 1;
		}
		if (swapv == root){
			return;
		}
		else {
			swap(array[root], array[swapv]);
			root = swapv;
		}
	}
	return;
}
