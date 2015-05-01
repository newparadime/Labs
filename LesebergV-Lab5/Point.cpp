//////////////////////////////////////
//Vinny Leseberg Lab 5
//Member Function Code for Circle.h
//////////////////////////////////////

#include <iostream>
#include "Point.h"

//Constructors
Point::Point(double x, double y)
{
	Point::SetXandY(x, y);
}

//Accesors
double Point::GetX()
{
	return xCoordinate;
}
double Point::GetY()
{
	return yCoordinate;
}
void Point::PrintPoint()
{
	std::cout << "The coordinates of the center of this cricle are: "
		<< xCoordinate << ", " << yCoordinate << ".";
}

//Mutators
void Point::SetX(double x)
{
	xCoordinate = x;
}
void Point::SetY(double y)
{
	yCoordinate = y;
}
void Point::SetXandY(double x, double y)
{
	SetX(x);
	SetY(y);
}