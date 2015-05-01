/////////////////////////////////////////
// Vincent Leseberg CST 138-02
// BONUS
// Purpose: Test Various Pointer Functions
//
/////////////////////////////////////////

#include <iostream>
#include <limits>

//Declare Constants
int const ARRAY_SIZE = 25;

//Define Functions
void Largest(int *const first, int *const last, int *largest);
bool Value(int *matrix, int value, int* &positionPtr);
int* NewArray(int *arraySize = new int);
void clearBuffer();

//Main Program Function
int main()
{
	//Declare Variables for Task 1
	int arraySize;
	int *matrixLargest;
	int largest;

	//Create Array for Task 1 (note that I use the function for task 3
	// here, so I have ommited a separate test for Task 3)
	matrixLargest = NewArray(&arraySize);

	//Print First and Last Address of Task 1 Array
	std::cout << "The address of the first element of this new array is: "
		<< matrixLargest
		<< "\n\nThe address of the last element of this new array is: "
		<< &matrixLargest[arraySize - 1];

	//Fill Task 1 Array with random Values
	for (int i = 0; i < arraySize; i++)
	{
		matrixLargest[i] = rand();
	}

	//Call Function to determine largest element of Task 1 Array
	Largest(&matrixLargest[0], &matrixLargest[arraySize - 1], &largest);

	//Output the *value* of the largest element of Task 1 Array
std::cout << "\n\nThe largest value in the array is: "
<< largest << "\n\n";

//Declare Task 2 Variables
int matrixValue[ARRAY_SIZE];
int value;
//Note that this is initialized to 'NULL' from the get-go
// so it is unecessary to do so in the function
int* valueAddress = NULL;
bool moreThanOnce;

//Fill Task 2 Array with random values
for (int i = 0; i < ARRAY_SIZE; i++)
{
	matrixValue[i] = rand() % 50;
}

//Query the user for the value they would like to search for
std::cout << "Please enter a value you would like to search for: ";
std::cin >> value;

//Call the function find the above value, which returns a boolean
// flag to alert the program if the value occured multiple times
moreThanOnce = Value(matrixValue, value, valueAddress);

//Check if the address for the value when found was 'NULL'
// and tell the user that the value was not found
if (valueAddress == NULL) std::cout << "\n The value was not found\n\n";

//Checks if the 'moreThanOnce' flag was thrown, if so, output
// the final address that the value occured at
else if (moreThanOnce)
{
	std::cout << "\nThe value was found more than once.\n"
		<< "The address of the last occurence is: "
		<< valueAddress << "\n\n";
}

//Otherwise simply tell the user what address the value was found at
else std::cout << "The value was located at memory address: "
<< valueAddress << "\n\n";

return 0;
}

//Function to locate the largest element of the array.
void Largest(int *const first, int *const last, int *largest)
{
	for (int *i = first; i < last; i++)
	{
		if (*i > *(i + 1))
		{
			*largest = *i;
		}
		else
		{
			*largest = *(i + 1);
		}
	}
}

//Function to find the what address the value occurs at.
// Note that the 'positionPtr' is a pointer that is passed
// by reference, so that it can be changed.
bool Value(int *matrix, int value, int* &positionPtr)
{
	//Counter to determine if the value occurs multiple times
	int counter = 0;

	//Check array for occurances of value
	for (int *i = matrix; i < &matrix[ARRAY_SIZE - 1]; i++)
	{
		if (*i == value)
		{
			positionPtr = i;
			counter++;
		}
	}

	//Return the evaluation of counter larger than 1
	// (i.e. if the value occurs more than once.
	return (counter > 1);
}

//Function to build an array of a prescribed size. If the
// program needs to know the address of the last element, 
// the address of a variable for the array size can be passed
// fromfrom main. Otherwise the function creates a new integer
// as default parameter for the pointer 'arraySize'.
int* NewArray(int* arraySize)
{
	
	bool tooBig;
	//Ask user for array size and read it in
	std::cout << "Please input the size of the array you would like to create: ";
	std::cin >> *arraySize;

	//Check that the array size is a positive non zero integer
	// if not continue to ask the user for a correct array size.
	while (*arraySize <= 0 || std::cin.fail())
	{
		//Checks if the input threw the fail bit (i.e. non int or int too large)
		if (std::cin.fail())
		{
			//Call clear buffer function to clear the bad data in the buffer
			// and reset fail bit
			clearBuffer();
			//Ask for size again
			std::cout << "The size you entered overloaded the buffer\n"
				<< "or was not an integer.\n"
				<< "Please enter another number: ";
			std::cin >> *arraySize;
		}
		//If fail bit was not set, ask 
		else
		{
			std::cout << "You did not enter a positive value.\n"
				<< "Please enter a positive value for the array length: ";
			std::cin >> *arraySize;
		}
	}

	//Create and the array and return its address
	return new int[*arraySize];
}

//Function to clear the cin buffer of bad input
void clearBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}