////////////////////////////////
// Pointers - HW 1
//
// Vincent Leseberg
////////////////////////////////

#include <iostream>
#include <iomanip>


using namespace std;

//Constant Declarations
const int ARRAY_SIZE = 10;

//Functon Definitions
void TripleDouble(double *pointer);
void PrintFunction(int *arrayPointer);

int main(void)
{
	//Task 1
	//Declar Variables
	double number;
	double *numberPtr;

	//Init Variables
	number = 5.27;
	numberPtr = &number;

	//Program Messages - Output init value of number using dereffed pointer
	cout << "This is the value of \'number\' called using the pointer \'numberPtr\': "
		<< *numberPtr << endl << endl;

	//Function Call to Triple value of number, note that it is a void return
	//	function that allows the program to directly change the value
	//	of number b/c it knows it mem address
	TripleDouble(numberPtr);

	//Output value of number using dereffed pointer after tripling function
	cout << "This is the value of \'number\' after the \"Triple Number\" function was called: "
		<< *numberPtr << endl << endl;

	//Task 2
	//Declare Variables 
	int matrix[ARRAY_SIZE];
	int *matrixPtr;

	//Init array to values 1 through 10 with for loop
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		matrix[i] = i + 1;
	}

	//Assign matrix pointer value of matrix array (address of first component)
	matrixPtr = matrix;
	
	//Print value of matrix pointer from above assignment
	cout << "Pointed at the whole arrary, the value of matrixPtr is: "
		<< matrixPtr << " .\n\n";
	
	//Assign matrix pointer address of first element of array directly
	//	same end result as above
	matrixPtr = &matrix[0];

	//Print value of array pointer after second assignment...they are the same
	cout << "Pointed at the first element with the refrence operator,"
		 << " the value of matrixPtr is: " << matrixPtr << " .\n\n";

	//Print array using pointer addition and for loop
	cout << "These are the values in the array: \n\n";
	for (int *i = matrixPtr; i < matrixPtr + ARRAY_SIZE; i++)
	{
		cout << *i << ",  ";
	}
	cout << endl << endl;

	//Task 3
	//Increase each value in array by one using pointer and single operation
	//	Note attention to precedence of operations in the expression
		while (matrixPtr <= &matrix[ARRAY_SIZE - 1])
	{
		++(*matrixPtr++);
	}

	//Reset matrix array pointer to first element of array
	matrixPtr = matrix;

	//Print values of Array using for loop and pointer
	for (int *i = matrixPtr; i < matrixPtr + ARRAY_SIZE; i++)
	{
		cout << *i << ",  ";
	}
	cout << endl << endl;

	//Increase values again
	while (matrixPtr <= &matrix[ARRAY_SIZE - 1])
	{
		++(*matrixPtr++);
	}

	//Reset array pointer again
	matrixPtr = matrix;

	//Print function accepts address of an int, sent address of array
	// element 0
	PrintFunction(&matrix[0]);

	//Declare constants for beginning and ending address of array
	const int *beginPtr = &matrix[0];
	const int *endPtr = &matrix[ARRAY_SIZE - 1];

	//Advance values by 1 using while loop and hard 
	//	value for address of last element
	while (matrixPtr <= &matrix[ARRAY_SIZE - 1])
	{
		++(*matrixPtr++);
	}

	//Reset array pointer value to matrix element 0
	matrixPtr = matrix;

	//Advance values by 1 using while loop and
	//	constant for address of last element
	while (matrixPtr <= endPtr)
	{
		cout << *matrixPtr++ << ",  ";
	}

}

//Tripling function uses dreffed passed address of pointer
void TripleDouble(double *pointer)
{
	*pointer *= 3;
}

//Print array using received pointer to first element
void PrintFunction(int *arrayPtr)
{
	for (int *i = arrayPtr; i < arrayPtr + ARRAY_SIZE; i++)
	{
		cout << *i << ",  ";
	}

	cout << endl << endl;
}