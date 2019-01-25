#include "insertion.h"

void InsertionSort::Run()
{
    int k = 1;
	int i = 1;
	assert(data[k-1] <= data[k]); //Loop Invariant
	for(k = 1; k < (int)data.size(); k++)
    {
		i = k;
        while(i > 0 && data[i] <= data[i - 1])
        {
            std::swap(data[i - 1],data[i]);
            i--;
			assert(data[k-1] <= data[k]); //Loop Invariant
        }
		assert(data[k-1] <= data[k]); //Loop Invariant
	}
	return;
}