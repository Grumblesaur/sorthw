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
	if (!hasLeftChild(index, arraySize)){
		return false;
	}
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

	//if this is the root of the heap, return
	if (!hasParent(index)){
		return;
	}
	
	//cout << "The value has a parent." << endl;
		
	while (hasParent(index)){
		//if the current element is greater than its parent
		if (array[index] > array[parentIndex(index)]){
			//swap the elements
			swap(array[index], array[parentIndex(index)]);
			//prepare to continue heapification from next element up
			index = parentIndex(index);
		}
		else if (array[index] <= array[parentIndex(index)]){
			return;
		}
		else if (index == 0){
			return;
		}	
	}

}
void heapifyDown(int array[], int arraySize){
	int swapIndex = -2; //arbitrary starting value for while loop
	int index = 0;
	
	while (swapIndex != -1){
		swapIndex = -1;
		if (hasLeftChild(index, arraySize)){
			if (array[leftChildIndex(index)] > array[index]){
				swapIndex = leftChildIndex(index);
				//cout << "Prepared to swap left child and parent" << endl;
			}
		}
		//
		if (hasRightChild(index, arraySize)){
			if (array[rightChildIndex(index)] > array[leftChildIndex(index)]){
				swapIndex = rightChildIndex(index);
				//cout << "Prepared to swap right child and parent" << endl;
			}
		}
		if (swapIndex != -1){
			swap(array[index], array[swapIndex]);
			index = swapIndex;
			//cout << "Swapped child, moved to new position" << endl;
		}
	}
}
