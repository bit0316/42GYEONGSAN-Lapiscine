/* stackL.c */
#include "stackL.h"

int isStackEmpty() {
	if (top == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void push(element item) {
	stackNode* newNode;

	newNode = (stackNode*)malloc(sizeof(stackNode));
	if (newNode == NULL)	return;

	newNode->data = item;
	newNode->link = top;

	top = newNode;
}

element pop() {
	stackNode* tr = top;

	if (!isStackEmpty()) {
		top = top->link;
		return tr->data;
	}
	else {
		return DATA_EMPTY;
	}
}

element peek() {
	if (!isStackEmpty()) {
		return top->data;
	}
	else {
		return DATA_EMPTY;
	}
}

void printStack() {
	stackNode* tr = top;

	printf("\nSTACK [ ");
	while (tr != NULL) {
		printf("%d ", tr->data);
		tr = tr->link;
	}
	printf("]");
}
