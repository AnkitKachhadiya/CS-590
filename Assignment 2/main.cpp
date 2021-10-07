#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "timer.h"
#include "random_generator.h"


int main(int argc, char* argv[])
{ 
	random_generator rg;
	timer t;
	int n, m, algo;

	n = 1000;
	m = 25;
	algo = 1;

	/*
	 * check arguments
	 */
	if (argc > 1)
	{ 
		n = atoi(argv[1]);
		n = (n < 1) ? 1 : n;
	}
	else
	{
		cout << argv[0] << " [n] [m] [algo]" << endl;
		cout << "[n]              size of the random string array" << endl;
		cout << "[m]              length of the strings" << endl;
		cout << "[algo]           0: run radix sort with insertion sort" << endl;
		cout << "                 1: run radix sort with counting sort" << endl;
		cout << endl;
		return 0;
	}

	if (argc > 2)
	{
		m = atoi(argv[2]);
		m = (m < 0) ? 0 : m;
	}

	if (argc > 3)
		algo = atoi(argv[3]);

	/*
	 * allocate and generate random strings
	 */
	char** input_array;
	int* input_length;

	input_array = new char*[n];
	input_length = new int[n];

	t.start();
	for (int i = 0; i < n; i++)
		input_array[i] = rg.random_string(m, input_length[i]);
	t.stop();

	cout << "Timer (generate): " << t << endl;

	// for (int i = 0; (i < n) && (i < 20); i++)
	// 	cout << input_array[i] << endl;
	// cout << endl;

	/*
	 * run algorithms
	 */
	if (algo == 0)
	{
		cout << "Running radix sort with insertion sort algorithm: " << endl;
		t.start();
		radix_sort_is(input_array, input_length, n, m);
		t.stop();
	} 
	else
	{
		cout << "Running radix sort with counting sort algorithm: " << endl;
		t.start();
		radix_sort_cs(input_array, input_length, n, m);
		t.stop();
	}

	cout << "Timer (sort): " << t << endl;

	/*
	 * check output
	 */
	if (check_sorted(input_array, 0, n-1))
		cout << "The output is sorted!" << endl;
	else
		cout << "ERROR: The output is not sorted!" << endl;

	  // for (int i = 0; (i < n) && (i < 20); i++)
	  //   cout << input_array[i] << endl;
	  // cout << endl;

	/*
	 * free allocated storage
	 */
	for (int i = 0; i < n; i++)
		delete[] input_array[i];
	delete[] input_array;
	delete[] input_length;

	return 0;
}

