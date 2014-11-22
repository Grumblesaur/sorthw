void swap(int & x, int & y){

	int temp;
	temp = x;
	x = y;
	y = temp;

}

bool hasLeftChild(int array[], int index, int arraySize){
	//finish this function

	return false;
}

bool hasRightChild(int array[], int index, int arraySize){
	if (!hasLeftChild(array, index, arraySize)){
		return false;
	}

	//finish this function
}

void heapifyUp(/* finish this function signature */);
void heapifyDown(/* finish this function signature */);

int leftChildIndex(int index){
	
	return (2 * index) + 1;
}

int rightChildIndex(int index){

	return (2 * index) + 2;
}

int parentIndex(int index){

	return (index - 1) / 2;

}
