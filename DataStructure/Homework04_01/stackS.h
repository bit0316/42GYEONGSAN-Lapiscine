/* stackS.h */
#pragma once
#define STACK_SIZE	100
#define FALSE		0
#define TRUE		!FALSE

typedef int element;
element stack[STACK_SIZE];

int isStackEmpty();
int isStackFull();
void push(element item);
element pop();
element peek();
void printStack();
