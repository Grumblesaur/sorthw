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

void heapifyUp(int array[], int numItems){
	
	int index = numItems - 1;
	
	while (array[index] > array[parentIndex(index)]){
		swap(array[index], array[parentIndex(index)]);
		index = parentIndex(index);
	}

}
void heapifyDown(int array[], int arraySize){
	
	int index = 0;
	int swapIndex;
	bool unheapified = true;
	while (unheapified){
		
		if (array[index] < array[leftChildIndex(index)]){
			swapIndex = leftChildIndex(index);
			if (array[rightChildIndex(index)] > array[leftChildIndex(index)]){
				swapIndex = rightChildIndex(index);
			}
		swap(array[index], array[swapIndex]);
		index = swapIndex;
		
		} else {
			unheapified = false;
		}
	}
}
