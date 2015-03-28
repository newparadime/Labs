//////////////////////////////////////
//Vinny Leseberg Lab 4
//Header File For Circle Class
//////////////////////////////////////

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
public:
	
	//Constructors
	Circle(double rad);
	Circle();
	
	
	//Predicate Functions
	bool IsPoint();

	//Accessor Functions
	double GetRadius();
	double GetDiameter();
	double GetArea();
	double GetCircumference();

	double GetArc(double angleDeg);

	void PrintDetails();

	//Mutator Functions
	void SetRadius(double rad);

//Private Functions
private:
	double radius;
};
#endif