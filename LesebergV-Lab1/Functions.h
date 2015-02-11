using namespace std;

int GCD(int a, int b)
{
	if (a + b == 0)
	{
		return 0;
	}
	else if (a == 0)
	{
		return b;
	}
	else if (a % 2 + b % 2 == 0)
	{
		return 2 * GCD(a / 2, b / 2);
	}
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
	else if (a % 2 == 0)
	{
		
		return GCD(a / 2, b);
	}
	else
	{
		return GCD(a, b / 2);
	}
}

double exp(double y, int x, int base = 0)
{
	if (base == 0) base = static_cast<int>(y);

	if (x == -1)
	{
		return y;
	}
	else if (x == 1)
	{
		cout << y;
		return exp(y, 0-static_cast<int>(y));
	}
	else if (x > 1)
	{
		cout << y << endl << x << endl;
		return exp(y * base, x - 1, base);
	}
	else
	{
		cout << y << endl << x << endl;
		return exp(y * base, x + 1, base);
	}
}