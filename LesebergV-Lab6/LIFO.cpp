#include "LIFO.h"
//#include "stack.h"

LIFO::LIFO(){}

element* LIFO::pop()
{
	element* temp = nullptr;

	if (!this->empty())
	{
		temp = new element;

		*temp = *last;

		delete last;

		if (*temp == *first)
		{
			last = nullptr;
			first = nullptr;
		}

		else
		{
			last = temp->previous;
		}
		size--;	
	}
	return temp;
}