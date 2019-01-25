#include "Sorter.h"

void Sorter::Run()
{
	InputRun();
}

void Sorter::AutoRun(int NUM_SORT, int NUM_ITEMS, int NUM_TRIALS)
{
	//Allocate memory for derived sort class
	if (NUM_SORT == 1)
		pSort = new InsertionSort(NUM_ITEMS);
	if (NUM_SORT == 2)
		pSort = new MergeSort(NUM_ITEMS);
	if (NUM_SORT == 3)
		pSort = new HeapSort(NUM_ITEMS);
            
	//Test the best, average, and worst cases
    for (int i = 0; i < NUM_TRIALS; i++)
    {
		pSort->RuntimeBestCase();
		pSort->RuntimeAverageCase();
		pSort->RuntimeWorstCase();
    }

	//Calculate and record the average runtimes of each case
    pSort->AverageVectors(NUM_ITEMS, NUM_TRIALS, fout[NUM_SORT-1]);

	//De-allocates memory and destroys object
    delete pSort;
    pSort = nullptr;
	return;
}

void Sorter::InputRun()
{
	do
	{
		//Prompt user for specifications
        cout << "\nChoose a Sort: \n\n";
		cout << "1. Insertion Sort \n";
		cout << "2. Merge Sort \n";
		cout << "3. Heap Sort \n";
		cout << "\n0. Exit Program \n" << endl;
		cin >> m_sort;

        //Check within bounds for input
        if(m_sort != 0 && m_sort <= m_total)
		{
			cout << "\nNumber of items: " << endl;
			cin >> m_items;

			//Run the sort
			if(m_items > 0)
				AutoRun(m_sort, m_items, 10);
		}
	}while(m_sort != 0);
	return;
}