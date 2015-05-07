#include "FIFO.h"
//#include "stack.h"

FIFO::FIFO(){}

element* FIFO::pop()
{
	element *temp = nullptr;

	if (!this->empty())
	{
		temp = new element;

		*temp = *first;
		
		delete first;

		if (*temp == *last)
		{
			last = nullptr;
			first = nullptr;
		}
		
		else
		{
			first = temp->next;
		}
		size--;
	}
	return temp;
}