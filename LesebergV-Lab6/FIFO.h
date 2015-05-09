#ifndef FIFO_H
#define FIFO_H
#include "stack.h"

class FIFO : public stack
{
public:
	FIFO();
	int* pop();
};

#endif