/* listS.c */
#include "listS.h"

int insertElement(int list[], int size, int element) {
	int position, target, move = 0;

	for (position = 0; position < size; position++) {
		if (list[position] >= element) {
			target = position;
			break;
		}
	}

	if (position == size) {
		target = position;
	}

	for (position = size; position > target; position--) {
		list[position] = list[position - 1];
		move++;
	}
	list[target] = element;

	return move;
}

int deleteElement(int list[], int size, int element) {
	int position, target = -1, move = 0;

	for (position = 0; position < size; position++) {
		if (list[position] == element) {
			target = position;
			break;
		}
	}

	if (position == size) {
		return size;
	}

	for (position = target; position < size - 1; position++) {
		list[position] = list[position + 1];
		move++;
	}

	return move;
}
