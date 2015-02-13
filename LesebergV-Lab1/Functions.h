using namespace std;

//------------
// Greatest Common Denominator Function
int GCD(int a, int b)
{
	//First base case if both integers are zero
	if (a + b == 0)
	{
		return 0;
	}

	//Second base case if either integer is not zero
	else if (a == 0)
	{
		return b;
	}
	
	//Case for two even integers
	else if (a % 2 + b % 2 == 0)
	{
		return 2 * GCD(a / 2, b / 2);
	}

	//Case for two odd integers
	else if (a % 2 * b % 2 != 0)
	{
		if (a >= b)
		{
			return GCD((a - b) / 2, b);
		}
		else
		{
			
			return GCD((b - a) / 2, a);
		}
	}

	//Case if b is odd and a is even
	else if (a % 2 == 0)
	{
		
		return GCD(a / 2, b);
	}
	
	//Case if a is odd and b is even
	else
	{
		return GCD(a, b / 2);
	}
}

//-----------------
// Function to raise y^x to y^x
double ExpBig(double y, int x, int base = 0)
{
	//Sets the initial base 'y' equal to 'base'
	if (base == 0) base = static_cast<int>(y);

	//Base case for when the ExpBigonent is 1
	//	(When counting up from ExpBigonent * -1)
	if (x == -1)
	{
		return y;
	}

	//Case reached when the initial value of y^x is reached
	else if (x == 1)
	{
		return ExpBig(y, 0 - static_cast<int>(y));
	}

	//Case when the ExpBigonent of the initial y^x calculation is 
	//	greater than one
	else if (x > 1)
	{
		return ExpBig(y * base, x - 1, base);
	}

	//Case when the ExpBigonent of the second y^x to the y^x
	//	calculation is greater than 1
	else
	{
		return ExpBig(y * base, x + 1, base);
	}
}

////-----------------
//// Function to raise y to the x (int overload)
//int exp(int y, int x)
//{
//	//Case reached when the value of y^x is reached (exp = 1)
//	if (x == 1)
//	{
//		return y;
//	}
//
//	//Case when the exponent of the initial y^x calculation is 
//	//	greater than one
//	else
//	{
//		return y * exp(y, x - 1);
//	}
//}
//
////-----------------
//// Function to raise y to the x (Double overload)
//double exp(double y, int x)
//{
//	//Case reached when the value of y^x is reached (exp = 1)
//	if (x == 1)
//	{
//		return y;
//	}
//
//	//Case when the exponent of the initial y^x calculation is 
//	//	greater than one
//	else
//	{
//		return y * exp(y, x - 1);
//	}
//}

//-----------------
// Function to raise y to the x (Template Class)
template <class T>
T exp(T y, int x)
{
	//Case reached when the value of y^x is reached (exp = 1)
	if (x == 1)
	{
		return y;
	}

	//Case when the exponent of the initial y^x calculation is 
	//	greater than one
	else
	{
		return y * exp(y, x - 1);
	}
}