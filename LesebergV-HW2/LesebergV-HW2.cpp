////////////////////////////////////////////////
// Vincent Leseberg
// Homework 2 - Dynamic Memory
////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//----------------------------------------------
	//Task 1
	int *intValue;

	double *dblValue;

	dblValue = new double;

	intValue = new int;
	
	*intValue = 10;

	*dblValue = 7.65;

	cout << *intValue << endl << *dblValue << endl;

	int *const constIntPointer = new int;

	*constIntPointer = 725;

	//This will not work because the memory address cannot be changed...
	// the pointer is constant...ie it points to a constant location
	//constIntPointer ++;

	//Note the parentheses that are required for the compiler to
	// understand that we are incrementing the value and not the
	// memory address
	(*constIntPointer) ++;

	int const *constIntValuePointer = new int(12);

	cout << *constIntValuePointer << endl << endl;
	
	//This will not work becayse the value the pointer is pointing
	// to cannot be changed. It is pointing to a constant type
	//constIntValue = 17;


	//----------------------------------------------
	//Task 2
	int *myArray = new int[10];

	for (int i = 0; i < 10; i++)
	{
		myArray[i] = 2 * i;
	}

	for (int i = 0; i < 10; i++)
	{
		*(myArray + i) = 2 * i;
	}
	//This could be done in reverse because the 'myArray' pointer is
	// never actually incremented in the loop. If 'myArray' was
	// incremented then it would be pointing at a different location
	// and then it wouldn't work.


	//----------------------------------------------
	//Task 3
	int **matrix = new int* [5];

	for (int i = 0; i < 5; i++)
	{
		*(matrix + i) = new int[10];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			*(*(matrix + i) + j) = j + i * 10;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(3) << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}
	
	return 0;
}