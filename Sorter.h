#ifndef SORTER_H
#define SORTER_H

#include <cmath>
#include "sorting/sort.h"
#include "sorting/insertion.h"
#include "sorting/merge.h"
#include "sorting/heap.h"
#include "SimpleApp.h"
using namespace std;

class Sorter : public SimpleApp
{
protected:
	Sort* pSort;			                 //Pointer to the base Sort class
	ofstream fout[3];	                     //Writes data to files
	int m_sort, m_items, m_trials, m_total;  //variables for data collection

public:
	virtual ~Sorter() {}

	void Run();
	
	//Purpose: Automatically runs testing, given parameters.
	virtual void AutoRun(int NUM_SORT, int NUM_ITEMS, int NUM_TRIALS);

	//Purpose: Allows the user to input parameters for testing.
	virtual void InputRun();

	Sorter()
    {
		pSort  = nullptr;
		fout[0].open("Output/data_insert.txt");
		fout[1].open("Output/data_merge.txt");
		fout[2].open("Output/data_heap.txt");
		m_total = 3;
    }
};
#endif
