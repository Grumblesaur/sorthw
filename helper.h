#ifndef HELPER_H
#define HELPER_H

void swap (int & x, int & y);

bool hasLeftChild(int index, int arraySize);

bool hasRightChild(int index, int arraySize);

bool hasParent(int index);

void heapifyUp(int array[], int index);

void heapifyDown(int array[], int start, int heapSize);

int leftChildIndex(int index);

int rightChildIndex(int index);

int parentIndex(int index);

#endif
