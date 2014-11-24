#ifndef HELPER_H
#define HELPER_H

void swap (int & x, int & y);

bool hasLeftChild(int index, int arraySize);

bool hasRightChild(int index, int arraySize);

void heapifyUp(int array[], int highestIndex);

void heapifyDown(/* in progress */);

int leftChildIndex(int index);

int rightChildIndex(int index);

int parentIndex(int index);

#endif
