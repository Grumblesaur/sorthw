#ifndef HELPER_H
#define HELPER_H

void swap (int & x, int & y);

bool hasLeftChild(int index, int arraySize);

bool hasRightChild(int index, int arraySize);

bool hasParent(int index);

void heapifyUp(int array[], int arraySize);

void heapifyDown(int array[], int arraySize);

int leftChildIndex(int index);

int rightChildIndex(int index);

int parentIndex(int index);

#endif
