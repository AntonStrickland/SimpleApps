#ifndef MERGE_H
#define MERGE_H

#include <limits>
#include "sort.h"
using namespace std;

class MergeSort : public Sort
{
protected:
    virtual ~MergeSort() {}

	//Runs the Merge Sort procedure
    virtual void Run();
	
	//Purpose: Recursive function for merge sort
	//Pre-Condition: Is called from a base function, i.e. run()
	//Post-Condition:  Returns a reference to the sorted array
	void M_Sort(std::vector<int> &merged, int first, int last);
	
	//Purpose: Merges two arrays together
	//Pre-Condition: A[pÅck-1] contains 0 elements of L and R at initialization
	//Invariant: A[pÅck-1] contains the k - p smallest elements of L and R in sorted order
	//Post-Condition: : A[pÅck-1] contains all but the two sentinels since k = r+1 at termination
	void Merge(std::vector<int> &merged, int first, int last);

public:
    MergeSort(int size) : Sort(size) {}
};
#endif
