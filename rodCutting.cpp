#include <iostream>
#include <algorithm>

using namespace std;

// Assign a global arraySize
int const arraySize = 12;

// array that holds the test information for sub problem 1
int const p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };


// Function prototypes

// Function to cut a "rod" in a top down fashion using recursion
int memoizedCutRod(int n);

// Function to create the top down memoized dynamic algorithm for rod cutting.
int memoizedCutRodHelp(int n, int r[11]);


// Function to cut a "rod" in a top down fashion using recursion
int memoizedCutRod(int n)
{
	// Create an array that will be used to hold results
	int r[11] = { 0 };

	// for loop to loop through every value in the array and assign it to a large negative number
	for (int i = 0; i < 11; i++)
	{
		r[i] = -9999;
	}

	// pass all the values to the memoizedCutRodHelp function, and return the value that it returns.
	return memoizedCutRodHelp(n, r);
}

// Function to create the top down memoized dynamic algorithm for rod cutting.
int memoizedCutRodHelp(int n, int r[11])
{
	// delcare variables
	int q;

	// if the value stored in the help array is larger than 0 (so anything was added) return that value
	if (r[n] >= 0)
	{
		return r[n];
	}

	// if n is equal to zero, set the return value to 0 (this means the function has been called as many times as possible
	if (n == 0)
	{
		q = 0;
	}

	// else statement to set result to very small number and then compare it to values in the array
	else
	{
		// set q to a very small value
		q = -9999;

		// for loop to check result against each value in the array and any combinations of sub cuts
		for (int i = 1; i < n; i++)
		{
			// set result equal to the maximum valute between intself and values in the array
			q = max(q, p[i] + memoizedCutRodHelp(n - i - 1, r));
		}
	}

	// set the auxilary array at index n equal to the result
	r[n] = q;

	// return the result
	return q;
}
