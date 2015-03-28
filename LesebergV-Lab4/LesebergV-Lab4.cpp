/////////////////////////////////////////
// Vincent Leseberg CST 138-02
// Lab 4: Recursion
// Purpose: Test Class 'Circle'
// Inputs: None
// Outputs: Data of Object Type 'Circle'
/////////////////////////////////////////

//Includes
#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
	//Declare Variables
	double Circle1Radius;
	double Circle1Diameter;
	double Circle1Area;
	double Circle1Arc;
	double Circle1Circumference;
	
	//Declare Objects
	Circle Circle1;
	Circle Circle2(4);
	Circle Circle0(-5);

	//Print the Details for Each Circle
	cout << "Details for circle zero: \n";
	Circle0.PrintDetails();

	cout << "\nDetails for circle one: \n";
	Circle1.PrintDetails();

	cout << "\nDetails for circle two: \n";
	Circle2.PrintDetails();

	//Change Radius of Circle 1
	Circle1.SetRadius(17);

	//Print the details of Circle 1 after Radius Change
	cout << "\nDetails for circle one after radius change: \n";
	Circle1.PrintDetails();

	//Test Accesor Functions
	Circle1Radius = Circle1.GetRadius();
	Circle1Diameter = Circle1.GetDiameter();
	Circle1Area = Circle1.GetArea();
	Circle1Arc = Circle1.GetArc(120);
	Circle1Circumference = Circle1.GetCircumference();
	
	//Print results of Accessor Functions
	cout << "\nThe following variables are the results of the\n"
		<< "tests of the accessor functions...\n"
		<< "Radius " << Circle1Radius << "\nDiameter " << Circle1Diameter
		<< "\nArea " << Circle1Area << "\n120 Deg Arc " << Circle1Arc
		<< "\nCircumference " << Circle1Circumference << "\n\n";

	//Declare a matrix of Circles
	Circle matrix[5];

	//Use a loop to Set the radius of each circle
	for (int i = 0; i < 5; i++)
	{
		matrix[i].SetRadius(i + 7);
	}

	//Print the Details of Each circle in the Array
	for (int i = 0; i < 5; i++)
	{
		cout << "\nThese are the details for Circle " << (i + 1) << " of 5.\n";
		matrix[i].PrintDetails();
		cout << "\n\n";
	}

	//Test memberwise assignment for Circle 2
	Circle duplicate = Circle2;

	//Print the details of the Duplicate Circle
	cout << "These are the details for the Duplicate Circle\n";
	duplicate.PrintDetails();
}