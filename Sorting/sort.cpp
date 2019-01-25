////////////////////////////////////
//             SORT               //
//          BASE CLASS            //
//        IMPLEMENTATION          //
//								  //
//   All arrays are ZERO-BASED,   //
//   but index A[0] is IGNORED!   //
////////////////////////////////////

#include "sort.h"

void Sort::RuntimeBestCase()
{
    //Set each data value to the best case
    for (unsigned int i = 1; i < data.size(); i++)
	{
		data[i] = i;
	}

    //Begin the timer and run the sort
    Timer(RunningTime::BEST);
    return;
}

void Sort::RuntimeAverageCase()
{
    //Set each data value to the average case
    for (unsigned int i = 1; i < data.size(); i++)
    {
        data[i] = rand()%data.size();
    }

    //Begin the timer and run the sort
	Timer(RunningTime::AVERAGE);
    return;
}

void Sort::RuntimeWorstCase()
{
    //Set each data value to the worst case
    for (int i = data.size()-1; i > 0; i--)
	{
        data[i] = data.size()-i;
	}

    //Begin the timer and run the sort
	Timer(RunningTime::WORST);
    return;
}

void Sort::Timer(const RunningTime CASE)
{
    //Set up the timer using the high resolution clock
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    //Run the sort
    Run();

    //Calculate the time taken (in milliseconds)
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double,std::ratio<1,1000>>>(t2 - t1);
    double counter = time_span.count();

    //Push the data (run time) into appropriate vector for later use
    if (CASE == RunningTime::WORST)
        worst_times.push_back(counter);
    else if (CASE == RunningTime::AVERAGE)
        average_times.push_back(counter);
    else if (CASE == RunningTime::BEST)
        best_times.push_back(counter);

    return;
}

void Sort::AverageVectors(const int NUM_ITEMS, const int NUM_TRIALS, ofstream &fout)
{
    
	//Calculate the average of all elements in each vector
    double avg_b = 0;
    double avg_a = 0;
    double avg_w = 0;

    for (unsigned int i = 0; i < NUM_TRIALS; i++)
    {
        if (i < best_times.size())
			avg_b += best_times[i];
		if (i < average_times.size())
			avg_a += average_times[i];
        if (i < worst_times.size())
			avg_w += worst_times[i];
    }

    avg_a /= NUM_TRIALS;
    avg_b /= NUM_TRIALS;
    avg_w /= NUM_TRIALS;

	if(fout.is_open())
	{
		//Write these averages to a file
		fout << NUM_ITEMS << " B.Avg: " << avg_b << endl;
		fout << NUM_ITEMS << " A.Avg: " << avg_a << endl;
		fout << NUM_ITEMS << " W.Avg: " << avg_w << endl;
	}
    

    return;
}

void Sort::OutputData()
{
	//Outputs data to the terminal
	cout << "Data: ";
	for(unsigned int i = 0; i < data.size(); i++)
	{
			cout << "[" << data[i] << "]";
	}
	cout << endl;
	return;
}
