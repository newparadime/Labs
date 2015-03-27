#include <iostream>
#include <iomanip>
#include <cmath>
#include "Circle.h"

const double PI = 3.14159265359;
using namespace std;

Circle::Circle()
{
	radius = 0;
}

Circle::Circle(double rad)
{
	if (radius >= 0)
	{
		SetRadius(rad);
	}
	else SetRadius(0);	
}

bool Circle::IsPoint()
{
	return (radius == 0);
}

double Circle::GetRadius()
{
	return radius;
}

double Circle::GetDiameter()
{
	return radius * 2;
}

double Circle::GetArea()
{
	return  PI * pow(radius, 2);
}

double Circle::GetCircumference()
{
	return PI * radius * 2;
}

double Circle::GetArc(double angleDeg)
{
	return radius * PI / 180;
}

void Circle::PrintDetails()
{
	if (Circle::IsPoint())
	{
		cout << "This object is a point.";
	}
	else
	{
		cout << "This object is a circle.\n"
			<< "It's Radius is " << Circle::GetRadius()
			<< "\n It's Circumference is " << Circle::GetCircumference()
			<< "\n It's Diameter is " << Circle::GetDiameter()
			<< "\n It's Area is " << Circle::GetArea();
	}
}

void Circle::SetRadius(double rad)
{
	radius = rad;
}

