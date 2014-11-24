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

        return (index - 1) / 2;

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

void heapifyUp(int array[], int arraySize){
		
	int index = arraySize - 1;
	if (!hasParent(index)){
		return;
	}
	
	while (array[index] > array[parentIndex(index)]){
		swap(array[index], array[parentIndex(index)]);
		index = parentIndex(index);
	}

}
void heapifyDown(int array[], int arraySize){
		
	int index = 0;
	int swapIndex;
	bool unheapified = true;
	
	//if the heap property isn't fulfilled
	while (unheapified){
		//if there's a left child	
		if (hasLeftChild(index, arraySize)){
			//and it's greater than its parent
			if (array[index] < array[hasLeftChild(index, arraySize)]){
				//prepare to swap them
				swapIndex = leftChildIndex(index);
			}
			//but if there's a right child
			if (hasRightChild(index, arraySize)){
				//and it's greater than the left child
				if (array[rightChildIndex(index)] > array[leftChildIndex(index)]){
					//prepare to swap to it instead
					swapIndex = rightChildIndex(index);
				}
			}
		//swap
		swap(array[index], array[swapIndex]);
		//set up to do next swap down if necessary
		index = swapIndex;
		
		} else {
			//the heap property is fulfilled and the loop will terminate
			unheapified = false;
		}
	}
}
