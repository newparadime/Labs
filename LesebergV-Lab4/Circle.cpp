//////////////////////////////////////
//Vinny Leseberg Lab 4
//Member Function Code for Circle.h
//////////////////////////////////////

#include <iostream>
#include <cmath>
#include "Circle.h"

//Declare Constant for PI
const double PI = 3.14159265359;
using namespace std;

//Default Constructor
Circle::Circle()
{
	radius = 0;
}

//Paramaterized Constructor
Circle::Circle(double rad)
{
	SetRadius(rad);	
}

//Check if Circle is a Point
bool Circle::IsPoint()
{
	return (radius == 0);
}

//Return Radius of Circle
double Circle::GetRadius()
{
	return radius;
}

//Return Diameter of Circle
double Circle::GetDiameter()
{
	return radius * 2;
}

//Return Area of Circle
double Circle::GetArea()
{
	return  PI * pow(radius, 2);
}

//Return Circumference of Circle
double Circle::GetCircumference()
{
	return PI * radius * 2;
}

//Return Arc Length for Internal Angle in Degrees
double Circle::GetArc(double angleDeg)
{
	return radius * PI / 180;
}

//Print Details of Circle
void Circle::PrintDetails()
{
	//Check If Circle is Point and return that
	if (Circle::IsPoint())
	{
		cout << "This object is a point.\n";
	}
	
	//If Not a point, Print details
	else
	{
		cout << "This object is a circle.\n"
			 << "It's Radius is " << Circle::GetRadius()
			 << "\nIt's Circumference is " << Circle::GetCircumference()
			 << "\nIt's Diameter is " << Circle::GetDiameter()
			 << "\nIt's Area is " << Circle::GetArea() << "\n";
	}
}

//Set the Radius of the Circle
void Circle::SetRadius(double rad)
{
	if (rad > 0)
	{
		radius = rad;
	}
	else
	{
		radius = 0;
	}
}

