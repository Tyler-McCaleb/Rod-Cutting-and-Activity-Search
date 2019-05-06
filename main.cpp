/*
	Tyler McCaleb
	April 6, 2019
	Algorithms Assinment #3

	Program will implement  both top-down version of the dynamic programming for rod-cutting algorithm 
	as well as a greedy algorithm for activity selection.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Assign a global arraySize
int const arraySize = 12;

// array that holds the test information for sub problem 1
int const p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

// Vector to hold the results of  the bottom up rod cutting 
vector<int> br;
vector<int> bs;

// Function prototypes

//  function to print a price
void printPrice();

//*********************** Sub Project 1 Functions ***************************
// Function t run sub Project one
void subProjectOne();

// Function to cut the rod bottom up.
void bottomUp(int n);



//*********************** Sub Project 2 Functions ***************************
// Function to perforom the search
void greedyActivitySearch(vector<int> s, vector<int> f, vector<int> &A, vector<int> activityList);

// function to load values into vecotrs
void loadVectors(int info[11],vector<int> &container);

// Function to run sub project two
void subProjectTwo();

int main()
{
	// Inform the user what the program is going to do
	cout << "This program will solve two problems." << endl;
	cout << "Press enter to display the first problem." << endl;
	cin.get();
	system("CLS");

/*
_________________________________________________________________________

------------------- Sub Project 1
_________________________________________________________________________
*/
	subProjectOne();
	system("CLS");
/*
_________________________________________________________________________

------------------- Sub Project 2
_________________________________________________________________________
*/
	subProjectTwo();

	cout << "\nPress any key to exit." << endl;
	cin.get();
	return 0;
}



// function definitions

//**************************** Subproject 1 Functions ************************

// function to demonstrate sub project 1
void subProjectOne()
{
	// variable to hold lengths for printing.

	int n = 0;
	// Inform the user of the problem and explain the table.
	cout << "The first sub project involves solving a Rod Cutting Problem using Dynamic programming to achieve an optimal solution." << endl;
	cout << "The rod lengths and values used for this problem are in the following table.\n" << endl;
	cout << "The length values are the lengths of the rod once cut.\nThe price values are how much a rod of the corresponding length is worth.\n" << endl;

	cout << "length (l)  |   1    2    3    4    5    6    7    8    9     10\n" << endl;
	cout << "price  (p)  |   1    5    8    9    10   17   17   20   24    30\n" << endl;

	cout << "The program will find the optimal to cut a rod that is 1 unit long up to a rod that is 10 units long.\nPress enter to find the optimal way to cut " << endl;
	cin.get();

	// Create the header for a table
	cout << "Rod Length\tPiece Lengths\tPrice" << endl;

	// Calculate the different lengths and output the  results to the table
	
	// Original Rod length = 1
	bottomUp(1);
	cout << "1\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 2
	bottomUp(2);
	cout << "2\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 3
	bottomUp(3);
	cout << "3\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 4
	bottomUp(4);
	cout << "4\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 5
	bottomUp(5);
	cout << "5\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 6
	bottomUp(6);
	cout << "6\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 7
	bottomUp(7);
	cout << "7\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 8
	bottomUp(8);
	cout << "8\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 9
	bottomUp(9);
	cout << "9\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();

	// Original Rod length = 10
	bottomUp(10);
	cout << "10\t\t";
	n = bs.size() - 1;
	while (n >= 0)
	{
		cout << bs[n] << " ";
		n = n - bs[n];
	}
	cout << "\t\t";
	printPrice();
	bs.clear();
	br.clear();


	cout << "Press Enter to continue..." << endl;
	cin.get();


	
	return;
}

// Function to perform a bottom up cutting
void bottomUp(int n)
{
	// declare variables
	int q;

	int *r;
	r = new int [n];
	int *s;
	s = new int [n];

	// Set the first index equal to zero since a rod with 0 length is worth 0
	r[0] = 0;

	// for loop to find each sub problem of size j
	for (int j = 1; j <= n; j++)
	{
		// set q to a very small value
		q = -9999;

		// limit the size of the cut by one each iteration.
		for (int i = 1; i <= j; i++)
		{
			if (q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}

		// set the maximum
		r[j] = q;
	}

	// load the global vectors with the correct sub-rod lengths
	for (int i = 0; i <= n; i++)
	{
		if (r[i] > 0)
		{
			br.push_back(r[i]);
		}
	}

	// load the global vectors with the correct sub-rod lengths
	for (int i = 0; i <= n; i++)
	{
		if (s[i] > 0)
		{
			bs.push_back(s[i]);
		}
	}

	return;
}


//**************************** Subproject 2 Functions ************************
void greedyActivitySearch(vector<int> s, vector<int> f, vector<int> &A, vector<int> activityList)
{
	// find the length of the set
	int n = s.size();

	// Assume the first activity is the best
	A.push_back(activityList[0]);

	// Variable to hold the most recent addition to the list
	int k = 1;

	// for loop to find the earliest activity
	for (int m = 2; m < n; m++)
	{
		// only add the next activity if it's start time is greater than or equal to the finish time of the activity before it.
		if (s[m] >= f[k])
		{
			// add the next activity of the list
			A.push_back(activityList[m]);
			
			// update the most recent addition to the result list
			k = m;
		}
	}
	return;
}

// function to load values into vecotrs
void loadVectors(int info[11], vector<int> &container)
{
	for (int i = 0; i < 11; i++)
	{
		container.push_back(info[i]);
	}
}

// Function to run sub project two
void subProjectTwo()
{
	// Arrays holding information for sub project 2
	int startTimes[11] = { 1, 3, 0, 5, 3, 5, 6 ,8, 8, 2, 12 };
	int finishTimes[11] = { 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16 };
	int activities[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	// Vectors with the start and finish information for sub project 2
	vector<int> start;
	vector<int> finish;
	vector<int> activityList;

	// Vector containing the activity list after a greedy search
	vector<int> activityResults;

	// load the vectors
	loadVectors(startTimes, start);
	loadVectors(finishTimes, finish);
	loadVectors(activities, activityList);

	string title = "Activity ";

	system("CLS");

	// Inform the user on what the problem is and what the information being used is.
	cout << "Sub Problem two involves solving an activity selection problem using a greedy search algorithm" << endl;
	cout << "This implementation is the iterative version of the algorithm" << endl;
	cout << "The following values are used for the problem:\n" << endl;

	cout << "Activity     |    1    2    3    4    5    6    7    8    9     10    11\n" << endl;
	cout << "Start Time   |    1    3    0    5    3    5    6    8    8     2     12\n" << endl;
	cout << "Finish Time  |    4    5    6    7    9    9    10   11   12    14    16\n" << endl;

	cout << "\nPress Enter to see the solution\n" << endl;
	cin.get();

	// Perform the search
	greedyActivitySearch(start, finish, activityResults, activityList);

	// Output the results
	cout << "The order of activities found by the program are: \n" << endl;

	for (int i = 0; i < activityResults.size(); i++)
	{
		cout << title + to_string(activityResults[i]) << "\t";
	}
	
	cout << "\n\nPress any key to continue." << endl;
	cin.get();
	system("CLS");
	return;
}

//  function to print a price
void printPrice()
{
	// variable to handle the  looping
	int n = bs.size() - 1;

	// variable to hold the total of the rod prices
	int total = 0;

	// While loop to check each value in the vector on the switch case
	while (n >= 0)
	{
		switch (bs[n])
		{
		case 0:
			total = total + p[0];
			break;
		case 1:
			total = total + p[1];
			break;
		case 2:
			total = total + p[2];
			break;
		case 3:
			total = total + p[3];
			break;
		case 4:
			total = total + p[4];
			break;
		case 5:
			total = total + p[5];
			break;
		case 6:
			total = total + p[6];
			break;
		case 7:
			total = total + p[7];
			break;
		case 8:
			total = total + p[8];
			break;
		case 9:
			total = total + p[9];
			break;
		case 10:
			total = total + p[10];
			break;
		default:
			break;
		}
		n = n - bs[n];
	}
	cout << total << endl;
	return;
}

