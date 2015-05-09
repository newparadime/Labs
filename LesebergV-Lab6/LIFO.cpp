#include "LIFO.h"
//#include "stack.h"

LIFO::LIFO(){}

int* LIFO::pop()
{
	int* temp = last;
	if (!this->empty())
	{
		*last-- = 0;
	}
	return temp;
}