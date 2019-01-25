////////////////////////////////////
//             SORT               //
//          BASE CLASS            //
//         DECLARATIONS           //
//								  //
//This class uses inheritance.	  //
//All sorts are derived from here.//
////////////////////////////////////

#ifndef SORT_H
#define SORT_H

#include <iostream>  //Basic I/O
#include <fstream>   //File I/O
#include <vector>    //Vectors to store lists to be sorted.
#include <cstdlib>   //Used to randomize the average case
#include <chrono>    //Used to measure running time
#include <cassert>   //Assert statements
using namespace std;

//Enumerations for each running time case
enum class RunningTime{
    BEST,
    AVERAGE,
    WORST
};

//Enumerations for each sorting number
enum SortNums
{
	SN_NULL,
	SN_INSERT,
	SN_MERGE,
	SN_HEAP
};

class Sort
{
private:
    //Description: Sets up the timer and then runs the appropriate sort.
    //Pre-Condition: CASE must equal 0, 1, or 2 for the running time to be saved in the vector.
    //Post-Condition: Pushes the running time into the appropriate vector.
    virtual void Timer(const RunningTime CASE);

    //Description: Runs the actual sort, dependent on the derived class.
    //Pre-Condition: Dependent on derived class.
    //Post-Condition: Vector "data" will be sorted.
    virtual void Run() = 0;

protected:
    vector<int> data;               //Vector containing data to be sorted.
    vector<double> best_times;      //Vector containing best case running times.
    vector<double> average_times;   //Vector containing average case running times.
    vector<double> worst_times;     //Vector containing worst case running times.
public:
	bool debug;						//Controls whether assert statements are processed
    Sort(const int NUM_ITEMS)
    {
        data.resize(NUM_ITEMS+1);
		debug = false;
    }

	virtual ~Sort() {}

    //Purpose: Computes the time taken to execute the sort in a best case scenario.
    //Pre-Condition: num_items is set to the desired value.
    //Post-Condition: Data will be sorted and running times recorded in a text file and vector.
    void RuntimeBestCase();

    //Purpose: Computes the time taken to execute the sort in an average case scenario.
    //Pre-Condition: num_items is set to the desired value.
    //Post-Condition: Data will be sorted and running times recorded in a text file and vector.
    void RuntimeAverageCase();

    //Purpose: Computes the time taken to execute the sort in a worst case scenario.
    //Pre-Condition: num_items is set to the desired value.
    //Post-Condition: Data will be sorted and running times recorded in a text file and vector.
    void RuntimeWorstCase();

    //Purpose: Computes the average of the three running time vectors
    //Pre-Condition: A vector which can be averaged exists.
    //Post-Condition: Returns the average.
    void AverageVectors(const int NUM_ITEMS, const int NUM_TRIALS, ofstream &fout);

	//Purpose: Outputs data  to the terminal, primarily for testing purposes.
	//Pre-Condition: Data exists.
	//Post-Condition: Data is output to the terminal.
	void OutputData();
};

#endif
