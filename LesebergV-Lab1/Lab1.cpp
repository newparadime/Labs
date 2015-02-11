/////////////////////////////////////
// Vincent Leseberg CST 138-02
// Lab 1: Recursion
// Purpose: 


#include <iostream>
#include "Functions.h"

using namespace std;

int main(void)
{
	//int a;
	//int b;
	//cin >> a;
	//cin >> b;
	//cout << GCD(a, b);
	int x;
	int y;
	int z = 1;
	while (z != 0)
	{
		cin >> z >> x >> y;
		cout << exp(x, y);
	}
	return 0;
}