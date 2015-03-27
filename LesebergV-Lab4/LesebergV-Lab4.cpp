/////////////////////////////////////////
// Vincent Leseberg CST 138-02
// Lab 4: Recursion
// Purpose: Test Class 'Circle'
// Inputs: None
// Outputs: Data of Object Type 'Circle'
/////////////////////////////////////////

#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
	double sillyRadius;
	double sillyDiameter;
	double sillyArea;
	double sillyArc;
	double sillyCircumference;
	
	Circle silly;

	Circle straight(4);
	
	Circle sad(-5);

	sad.PrintDetails;

	silly.SetRadius(17);

	sillyRadius = silly.GetRadius;
	sillyDiameter = silly.GetDiameter;
	sillyArea = silly.GetArea;
	sillyArc = silly.GetArc(120);
	sillyCircumference = silly.GetCircumference;
	
	Circle matrix[5];

	for (int i = 0; i < 5; i++)
	{
		matrix[i].SetRadius(i + 7);
	}


}