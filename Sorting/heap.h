#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include "sort.h"
using namespace std;

class HeapSort : public Sort
{
protected:
    virtual ~HeapSort() {}
    
	//Runs the Heap Sort procedure
	virtual void Run();

	//Purpose: Makes the node A[i] the root of a Max Heap
	//Pre-Condition: A[] is a non-empty array of integers
	//Post-Condition: A[i] is the root of a Max Heap
	void MaxHeapify(std::vector<int> &A, int i);

	//Purpose: Builds a Max Heap from A[], with A[1] as the root
	//Pre-Condition: A[] is a non-empty array of integers
	//Invariant: A[j] is the root of a Max Heap for j = i+1, i+2, ..., n
	//Post-Condition: Every element of A[] except A[0] is the root of a Max Heap
	void BuildMaxHeap(std::vector<int> &A);
	
	//Returns the left child of node A[i]
	int GetLeft(int i);
	
	//Returns the right child of node A[i]
	int GetRight(int i);
	
	//Returns the parent of node A[i]
	int GetParent(int i);
	
	//Returns true iff A[i] is a Max Heap for i, i+1, ..., n
	bool HeapTest(std::vector<int> &A, int i);

	int heapSize;
public:
    HeapSort(int size) : Sort(size)
    {heapSize = data.size();}
};
#endif
