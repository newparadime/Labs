/////////////////////////////////////////
// Vincent Leseberg CST 138-02
// Lab 5: Composition
// Purpose: Test Class 'Circle' w/ Compsoition
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
	std::pair<double, double> Circle1Center;



	//Declare Circle 0
	Circle Circle0(-5);

	//Print the Details for Circle 0
	cout << "Details for circle zero: \n";
	Circle0.PrintDetails();
	cout << Circle0.GetObjectCount() << " circle(s) have now been created.\n\n";

	//Declare Circle 1
	Circle Circle1;

	//Print the Details for Circle 1
	cout << "Details for circle one: \n";
	Circle1.PrintDetails();
	cout << Circle1.GetObjectCount() << " circle(s) have now been created.\n\n";

	//Declare Circle 2
	Circle Circle2(4, 3, 2);
	

	//Print the Details for Circle 2
	cout << "Details for circle two: \n";
	Circle2.PrintDetails();
	cout << Circle2.GetObjectCount() << " circle(s) have now been created.\n\n";

	//Change Radius of Circle 1
	Circle1.SetRadius(17);

	//Change Center of Circle 1
	Circle1.SetCenter(7, -2);

	//Print the details of Circle 1 after Radius and Center Change
	cout << "Details for circle one after radius change: \n";
	Circle1.PrintDetails();

	//Test Accesor Functions
	Circle1Radius = Circle1.GetRadius();
	Circle1Diameter = Circle1.GetDiameter();
	Circle1Area = Circle1.GetArea();
	Circle1Arc = Circle1.GetArc(120);
	Circle1Circumference = Circle1.GetCircumference();
	Circle1Center = Circle1.GetCenter();

	//Print results of Accessor Functions
	cout << "\nThe following variables are the results of the\n"
		<< "tests of the accessor functions...\n"
		<< "Radius " << Circle1Radius << "\nDiameter " << Circle1Diameter
		<< "\nArea " << Circle1Area << "\n120 Deg Arc " << Circle1Arc
		<< "\nCircumference " << Circle1Circumference
		<< "\nCenter " << Circle1Center.first << ", "
			<< Circle1Center.second << "\n\n";

	//Declare a matrix of Circles
	Circle matrix[5];
	cout << "A matrix of 5 \'Circles\' was created. "
		<< matrix[0].GetObjectCount() << " circles have been created.\n\n";


	//Use a loop to Set the radius of each circle
	for (int i = 0; i < 5; i++)
	{
		matrix[i].SetRadius(i + 7);
		cout << "These are the details for Circle " << (i + 1) << " of 5.\n";
		matrix[i].PrintDetails();
	}

	//Test memberwise assignment for Circle 2
	Circle duplicate = Circle2;

	//Print the details of the Duplicate Circle
	cout << "These are the details for the Duplicate Circle\n";
	duplicate.PrintDetails();

	

	

}