//////////////////////////////////////
//Vinny Leseberg Lab 5
//Member Function Code for Circle.h
//////////////////////////////////////

#include <iostream>
#include <cmath>
#include "Circle.h"

//Declare Constant for PI
const double PI = 3.14159265359;
using namespace std;

int Circle::counter = 0;

//Combined Paramaterized and Default Constructor
Circle::Circle(double rad, double x, double y)
{
	Circle::SetRadius(rad);
	//Circle::counter++;
	Circle::SetCenter(x, y);
	Circle::ObjectCount();
}

//Check if Circle is a Point
bool Circle::IsPoint()
{
	return (radius == 0);
}

//Return Center of Circle
std::pair<double,double>Circle::GetCenter()
{
	std::pair<double,double> ctr;
	ctr.first = center.GetX();
	ctr.second = center.GetY();
	return ctr;
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

//Return Number of Circles Created
int Circle::GetObjectCount()
{
	return counter;
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
			<< "Its Radius is " << Circle::GetRadius()
			<< "\nIts Circumference is " << Circle::GetCircumference()
			<< "\nIts Diameter is " << Circle::GetDiameter()
			<< "\nIts Area is " << Circle::GetArea() << "\n";
	}
	center.PrintPoint();
	cout << "\n\n";
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

void Circle::SetCenter(double x, double y)
{
	center.SetXandY(x, y);
}

void Circle::ObjectCount()
{
	counter++;
}