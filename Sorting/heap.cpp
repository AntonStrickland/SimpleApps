#include "heap.h"

int HeapSort::GetLeft(int i)  {return 2*i;}
int HeapSort::GetRight(int i) {return (2*i)+1;}
int HeapSort::GetParent(int i) {return floor(i/2.0);}

void HeapSort::Run()
{
	//Build the heap
	BuildMaxHeap(data);

	assert(HeapTest(data,1));	//assert it is a max heap

	//Sort the heap
	for (int i = data.size()-1; i > 1; i--)
	{
		std::swap(data[1],data[i]);
		heapSize--;
		MaxHeapify(data,1);
		assert(data[1] >= 0);  //assert the index contains data
	}
	assert(data[1] >= 0);  //assert the index contains data

	return;
}

void HeapSort::BuildMaxHeap(std::vector<int> &A)
{
	int length = A.size();
	heapSize = length;
	int i = floor(length/2.0);

	assert((A[1] > 0)||(A[1] <= 0)); //A[] is not empty

	//Build the max heap
	for(i = floor(length/2.0); i > 0; i--)
	{
		MaxHeapify(A,i);
		assert(HeapTest(A,i)); //verifies parent > children
	}
	
	assert(HeapTest(A,1));	//i = 1 because otherwise i would be 0
	return;
}

bool HeapSort::HeapTest(std::vector<int> &A, int i)
{
	//Get left and right children
	int l = GetLeft(i);
	int r = GetRight(i);

	//Check to see if the left child exists and is larger
	if(l <= heapSize-1 && A[l] > A[i])
		return false;
	//Check to see if the right child exists and is larger
	else if(r <= heapSize-1 && A[r] > A[i])
		return false;
	
	return true;
}

void HeapSort::MaxHeapify(std::vector<int> &A, int i)
{
	int largest = 0;

	//Get left and right children
	int l = GetLeft(i);
	int r = GetRight(i);

	//Check to see if the left child exists and is largest
	if(l <= heapSize-1 && A[l] > A[i])
		largest = l;
	else
		largest = i;
	
	//Check to see if the right child exists and is largest
	if(r <= heapSize-1 && A[r] > A[largest])
		largest = r;
	
	//If this node is not the largest, swap and recursively call
	if(largest != i)
	{
		std::swap(A[i],A[largest]);
		MaxHeapify(A, largest);
	}

	return;
}
