#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
public:
	//Constructor
	Circle();
	Circle(double rad);
	
	//Predicate
	bool IsPoint();

	//Accessor
	double GetRadius();
	double GetDiameter();
	double GetArea();
	double GetCircumference();

	double GetArc(double angleDeg);

	void PrintDetails();

	//Mutator
	void SetRadius(double rad);

private:
	double radius;
};
#endif