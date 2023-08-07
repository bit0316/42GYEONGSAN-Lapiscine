/* stackS.c */
#include "stackS.h"

int top = -1;

int isStackEmpty() {
	if (top < 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int isStackFull() {
	if ((top + 1) >= STACK_SIZE) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void push(element item) {
	if (!isStackFull()) {
		stack[++top] = item;
	}
	else {
		return;
	}
}

element pop() {
	if (!isStackEmpty()) {
		return stack[top--];
	}
	else {
		return 0;
	}
}

element peek() {
	if (!isStackEmpty()) {
		return stack[top];
	}
	else {
		return 0;
	}
}

void printStack() {
	printf("\n스택 출력 : ");
	for (int i = 0; i <= top; ++i) {
		printf("%d ", stack[i]);
	}
}
