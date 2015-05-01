//////////////////////////////////////
//Vinny Leseberg Lab 5
//Header File For Circle Class
//////////////////////////////////////

#ifndef POINT_H
#define POINT_H
class Point
{
public:
	//Constructors
	Point(double x = 0, double y = 0);

	//Accesors
	double GetX();
	double GetY();
	void PrintPoint();

	//Mutators
	void SetX(double x);
	void SetY(double y);
	void SetXandY(double x, double y);
	
	//Operator
	//Prefix
	Point & operator -- (void);
	//Postfix
	Point operator -- (int);
	
private:
	double xCoordinate;
	double yCoordinate;
};
#endif
