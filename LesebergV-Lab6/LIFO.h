#ifndef LIFO_H
#define LIFO_H
#include "stack.h"

class LIFO : public stack
{
public:
	LIFO();
	int* pop();
};

#endif