#ifndef STACK_H
#define STACK_H
#include "element.h"

//struct element
//{
//	int value;
//	element* previous;
//};

class stack	
{
public:
	stack();
	void push(int value);
	virtual element* pop() = 0;
	int peep() const;
	void clear();
	void dump();
	bool full() const;
	bool empty() const;
	int getSize() const;

protected:		
	int size;
	element *first;
	element *last;
};

#endif
