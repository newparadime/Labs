#include "FIFO.h"
//#include "stack.h"

FIFO::FIFO(){}

int* FIFO::pop()
{
	int* temp = last;
	if (!this->empty())
	{
		*first++ = 0;
	}
	return temp;
}

