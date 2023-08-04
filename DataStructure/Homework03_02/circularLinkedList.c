/* circularLinkedList.c */
#include "circularLinkedList.h"

linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;

	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL;

	return CL;
}

void printList(linkedList_h* CL) {
	listNode* tr;

	if (CL->head == NULL) {
		printf("\n\n");
		return;
	}

	tr = CL->head;

	do {
		printf("%s ", tr->data);
		tr = tr->link;
	} while (tr != CL->head && tr != NULL);
	printf("\n\n");
}

void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode;
	listNode* tr;

	newNode = (listNode*)malloc(sizeof(listNode));
	strncpy(newNode->data, x, DATA_SIZE);
	
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		tr = CL->head;
		while (tr->link != CL->head)
			tr = tr->link;
		newNode->link = tr->link;
		//newNode->link = CL->head;
		tr->link = newNode;
		CL->head = newNode;
	}
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strncpy(newNode->data, x, DATA_SIZE);

	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void deleteNode(linkedList_h* CL, listNode* p) {
	listNode* tr;

	tr = CL->head;

	if (CL->head != NULL) {
		while (tr->link != p)
			tr = tr->link;
		tr->link = p->link;
		if (p == CL->head)
			CL->head = p->link;
		free(p);
	}
}

listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* tr;

	tr = CL->head;

	while (tr != NULL) {
		if (strncmp(tr->data, x, DATA_SIZE) == 0)
			return tr;
		else
			tr = tr->link;
	}
	return tr;
}
