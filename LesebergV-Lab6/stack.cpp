#include <cmath>
#include <iostream>
#include "stack.h"

stack::stack() : last(nullptr), first(nullptr){}

int const MAX_SIZE = 1024 ^ 3;
int size = 0;

void stack::push(int value)
{
	if (!this->full())
	{
		element* temp = new element(value, last);
		last = temp;
		size++;
		if (first)
		{
			last->previous->next = last;
		}
		else first = last;
	}
	else std::cout << "The stack is full. The element was not added.\n\n";
}

int stack::peep() const
{
	return last->value;
}

void stack::clear()
{
	element* temp;
	while (last)
	{
		temp = last->previous;
		delete last;
		last = temp;
	}
	first = last;
	size = 0;
}

void stack::dump()
{
	if (this->empty())
	{
		std::cout << "This stack is empty.\n\n";
	}
	else
	{
		element* temp = first;
		while (temp != last)
		{
			std::cout << "| " << temp->value << " ";
			temp = temp->next;
		}
		std::cout << "| " << temp->value << " ";
		std::cout << "|\n\n";
	}
}

bool stack::full() const
{
	return (size >= MAX_SIZE);
}

bool stack::empty() const
{
	return (!last);
}

int stack::getSize() const
{
	return size;
}