/* stackL.h */
#include <stdlib.h>

#pragma once
#define DATA_EMPTY	0
#define FALSE		0
#define TRUE		!FALSE

typedef int element;

typedef struct {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();
