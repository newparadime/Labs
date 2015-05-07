#include "element.h"

element::element(int val, element* prev, element* nex)
{
	value = val;
	previous = prev;
	next = nex;
}

bool element::operator == (const element& b)
{
	if (this->value == b.value && this->previous == b.previous)
	{
		return true;
	}
	else return false;
}