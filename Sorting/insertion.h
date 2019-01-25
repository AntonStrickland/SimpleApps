#ifndef INSERTION_H
#define INSERTION_H

#include "sort.h"
using namespace std;

class InsertionSort : public Sort
{
protected:
    virtual ~InsertionSort() {}

	//Runs the Insertion Sort procedure
    virtual void Run();

public:
    InsertionSort(int size) : Sort(size) {}
};
#endif
