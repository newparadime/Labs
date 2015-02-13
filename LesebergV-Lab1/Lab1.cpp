/////////////////////////////////////
// Vincent Leseberg CST 138-02
// Lab 1: Recursion
// Purpose: 


#include <iostream>
#include "Functions.h"

using namespace std;

int main(void)
{
	int a;
	int b;

	//Tests the GCD function with two integers
	cout << "This function calculates the GCD"
		 << " for two integer numbers.\n\n"
		 << "Please enter an integer 'a': ";
	cin >> a;
	cout << "\nPlease enter and integer 'b': ";
	cin >> b; 
	cout << "The GCD of 'a' and 'b' is: " << GCD(a, b)
		<< "\n\n\n";

	int x;
	int y;

	//Tests exp function with an integer base
	//	and integer exponent
	cout << "This function calculates y^x\n\n"
		 << "Please enter an integer 'y':";
	cin >> y;
	cout << "\nPlease enter and integer 'x':";
	cin >> x;
	cout << "\n'y' raised to the power 'x' is: " << exp(y, x)
		<< "\n\n\n";

	double yFloat;

	//Tests exp function with a floating point base
	//	and integer exponent
	cout << "This function calculates y^x\n\n"
		 << "Please enter a floating point number 'y': ";
	cin >> yFloat;
	cout << "\nPlease enter an integer 'x': ";
	cin >> x;
	cout << "\n'y' raised to the power 'x' is: " << exp(yFloat, x)
		 << "\n\n\n";

	//This function calculates y raised to the x then raised to itself
	cout << "This function calculates y^x raised to y^x\n\n"
		<< "Please enter an integer 'y': ";
	cin >> yFloat;
	cout << "\nPlease enter an integer 'x': ";
	cin >> x;
	
	//Note a double is used in this function not because
	//	a floating point is needed, but because the values
	//	get very large and an int cannot store the data
	cout << "\n'y^x' raised to the power 'y^x' is: " << ExpBig(yFloat, x)
		<< "\n\n";

	return 0;
}

