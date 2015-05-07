#ifndef ELEMENT_H
#define ELEMENT_H

struct element
{
	element(int val = 0, element* prev = nullptr, element* nex = nullptr);
	int value;
	element* previous;
	element* next;

	bool operator == (const element& b);
};

#endif