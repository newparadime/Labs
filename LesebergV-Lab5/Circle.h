//////////////////////////////////////
//Vinny Leseberg Lab 5
//Header File For Circle Class
//////////////////////////////////////

#include "Point.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
	//Static Members
	static int counter;

	//Constructors
	Circle(double rad = 0, double xCenter = 0, double yCenter = 0);
	
	//Predicate Functions
	bool IsPoint();

	//Accessor Functions
	double GetRadius();
	double GetDiameter();
	double GetArea();
	double GetCircumference();
	std::pair<double, double>GetCenter();
	int GetObjectCount();

	double GetArc(double angleDeg);

	void PrintDetails();

	//Mutator Functions
	void SetRadius(double rad);
	void SetCenter(double x, double y);

	//Static Functions
	void ObjectCount();

	//Private Members
private:
	Point center;
	double radius;
	
};
#endif