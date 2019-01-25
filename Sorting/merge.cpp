#include "merge.h"

void MergeSort::Run()
{
	//Base Case call
	M_Sort(data, 1, data.size()-1);
	return;
}

void MergeSort::M_Sort(std::vector<int> &merged, int first, int last)
{
	//Checks to see if the array has at most one element
	if(first < last)
    {
	    //Recursively split up the array into two subarrays and sort them
		int middle = (first+last)/2;
        M_Sort(merged, first, middle);
		M_Sort(merged, middle+1, last);

		//Combine the two arrays back together
		Merge(merged, first, last);
	}
	return;
}

void MergeSort::Merge(std::vector<int> &merged, int first, int last)
{
	int i = 1;
	int j = 1;
	int k = first;
	int middle = (first+last)/2;
	
	//Calculate the sizes of the two subarrays
	int SIZE_L = middle - first + 1; 
	int SIZE_R = last - middle;

	//Create and resize the subarrays
	std::vector<int> left;
	std::vector<int> right;
	left.resize(SIZE_L+1);
	right.resize(SIZE_R+1);

	//Fill the subarrays with the data
	for(i = 1; i <= SIZE_L; i++)
		left[i] = merged[first+i-1];
	for(j = 1; j <= SIZE_R; j++)
		right[j] = merged[middle+j];

	//Add sentinels to the ends of the subarrays
	left.push_back(std::numeric_limits<int>::max());
	right.push_back(std::numeric_limits<int>::max());

	i = 1;
	j = 1;

	assert(merged[first] <= left[1]); //assert merged[] has smaller data

	//Merge the two arrays together
	//by comparing each value one by one
	for(k = first; k <= last; k++)
	{
		//If the left index is less than the right index,
		//place the left index into the new (sorted) array
		if(left[i] < right[j])
		{
			merged[k] = left[i];
			assert(left[i] <= merged[k]); //assert left[] has smaller data
			i++;
			
		}
		//If the right index is less than the left index,
		//place the right index into the new (sorted) array
		else
		{
			merged[k] = right[j];
			assert(right[j] <= merged[k]); //assert right[] has smaller data
			j++;
		}
		
	}

	//assert that either left or right has smaller data
	assert(left[i-1] <=  merged[last] || right[j-1] <= merged[last]);
	return;
}

