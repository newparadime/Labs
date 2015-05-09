#ifndef STACK_H
#define STACK_H

class stack	
{
public:
	stack();
	void push(int value);
	virtual int* pop() = 0;
	int* peep() const;
	void clear();
	void dump() const;
	bool full();
	bool empty() const;
	int getSize() const;
	int getMax() const;

protected:		
	int size;
	int maxSize;
	int* first;
	int* last;
	int* top;
	int* bottom;
	int inputSize(); 
	void shiftDown();
	int inputFail(int value);
	void clearBuffer();
};

#endif
