#include <iostream>
#include <typeinfo>
#include "LIFO.h"
#include "FIFO.h"
#include "stack.h"

void Welcome(int stackNum);
char GetStackType();
void Divider();
void Push(stack* currentStack);
void Pop(stack* currentStack);
void Peep(stack* currentStack);
void Status(stack* currentStack);
bool Menu(stack** matrix);

int main()
{
	stack* matrix[4];

	char stackType;

	for (int i = 0; i < 4; i++)
	{
		Welcome(i);
		stackType = GetStackType();
		while (stackType != 'L' && stackType != 'F')
		{
			std::cout << "That was not a valid selection\n\n";
			Welcome(i);
			stackType = GetStackType();
		}

		if (stackType == 'F')
		{
			matrix[i] = new FIFO;
		}
		else
		{
			matrix[i] = new LIFO;
		}
	}
	
	Menu(matrix);

	while (Menu(matrix));
	
	return 0;

}

void Welcome(int stackNum)
{
	std::cout << "Please select which type of stack you wish to"
		<< "create for stack " << stackNum + 1 << ".\n"
		<< "Enter 'F' for a FIFO or 'L' LIFO: ";
}

char GetStackType()
{
	char type;
	std::cin >> type;
	std::cout << "\n";
	return toupper(type);
}

bool Menu(stack** matrix)
{
	int stackNum;
	int option;

	std::cout << "\nPlease select a stack (1-4), or enter zero if done: ";
	std::cin >> stackNum;
	std::cout << "\n";
	if (stackNum)
	{
		stackNum--;
		std::cout 
			<< "1: Push an item to the stack\n"
			<< "2: Pop an item from the stack\n"
			<< "3: Peep the top item of the stack\n"
			<< "4: Empty the stack\n"
			<< "5: Dump the contents of the stack to the screen\n"
			<< "6: Get the current stack size\n\n"
			<< "Please select an operation: ";
		std::cin >> option;
		std::cout << "\n";
		switch (option)
		{
		case 1:
			Push(matrix[stackNum]);
			break;
		case 2:
			Pop(matrix[stackNum]);
			break;
		case 3:
			Peep(matrix[stackNum]);
			break;
		case 4:
			matrix[stackNum]->clear();
			break;
		case 5:
			std::cout << "The contents of the stack: \n\n";
			matrix[stackNum]->dump();
			break;

		case 6:
			Status(matrix[stackNum]);
			break;
		}
		return true;
	}
	else return false;
}

void Pop(stack* currentStack)
{
	if (!currentStack->empty())
	{
		if (typeid(*currentStack) == typeid(FIFO))
		{
			std::cout << "The first entry of the stack has been \'popped\'.\n";
		}
		else
		{
			std::cout << "The last entry of the stack has been \'popped\'.\n";
		}
		std::cout << "Its value is: " << currentStack->pop()->value << "\n\n";
	}
	else std::cout << "This stack is empty.\n\n";
}

void Push(stack* currentStack)
{
	int value;
	std::cout << "Please enter a value to add to the stack: ";
	std::cin >> value;
	currentStack->push(value);
	std::cout << "\n\n";
}

void Peep(stack* currentStack)
{
	if (!currentStack->empty())
	{
		std::cout << "The last value added to the stack was "
			<< currentStack->peep() << "\n\n";
	}
	else std::cout << "The stack is empty.\n\n";
}

void Status(stack* currentStack)
{
	if (currentStack->full())
	{
		std::cout << "The stack is full\n\n";
	}
	else if (currentStack->empty())
	{
		std::cout << "The stack is empty\n\n";
	}
	else std::cout << "The stack has " << currentStack->getSize()
		<< " elements in it.\n\n";
}