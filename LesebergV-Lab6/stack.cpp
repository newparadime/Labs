#include <cmath>
#include <iostream>
#include "stack.h"
#include "FIFO.h"

int size;
static int counter = 0;

stack::stack() : last(nullptr), first(nullptr)
{
	maxSize = inputSize();
	first = new int[maxSize];
	bottom = first;
	top = &first[maxSize - 1];
	counter++;
}

void stack::push(int value)
{
	if (!this->full())
	{
		if (last)
		{
			*++last = value;
			size++;
		}
		else
		{
			*first = value;
			first = last;
		}

	}
	else std::cout << "The stack is full. The element was not added.";
}

int* stack::peep() const
{
	return last;
}

void stack::clear()
{
	last = nullptr;
	first = bottom;
	size = 0;
}

void stack::dump() const
{
	if (this->empty())
	{
		std::cout << "This stack is empty.\n\n";
	}
	else
	{
		int* temp = first;
		while (temp <= last)
		{
			std::cout << "| " << *temp++ << " ";
		}
		std::cout << "|\n\n";
	}
}

bool stack::full()
{
	bool full = false;
	if (top == last)
	{ 
		if (first > bottom)
		{
			this->shiftDown();
		}
		else full = true;
	}

	return full;
}

bool stack::empty() const
{
	return !last;
}

int stack::getSize() const
{
	return size;
}

int stack::inputSize()
{
	int size;
	std::cout << "Please select the capacity of stack you wish to "
		<< "create for stack " << counter + 1 << ": ";
	std::cin >> size;

	size = inputFail(size);
	
	return size;
}

int stack::getMax() const
{
	return maxSize;
}

int stack::inputFail(int value)
{
	while (value <= 0 || std::cin.fail())
	{
		//Checks if the input threw the fail bit (i.e. non int or int too large)
		if (std::cin.fail())
		{
			//Call clear buffer function to clear the bad data in the buffer
			// and reset fail bit
			clearBuffer();
			//Ask for size again
			std::cout << "\nThe size you entered overloaded the buffer\n"
				<< "or was not an integer.\n\n"
				<< "Please enter another number: ";
			std::cin >> value;
		}
		//If fail bit was not set, ask 
		else
		{
			std::cout << "\nYou did not enter a positive value.\n\n"
				<< "Please enter a positive value for capacity\n"
				<< "of the stack you wish to create: ";
			std::cin >> value;
		}
	}
	return value;
}

void stack::clearBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void stack::shiftDown()
{
	for (int i = 0; i < size; i++)
	{
		bottom[i] = first[i];
	}
	first = bottom;
	last = first + size - 1;
}