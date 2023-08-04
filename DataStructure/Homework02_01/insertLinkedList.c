/* insertLinkedList.c */
#include "insertLinkedList.h"

linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;

	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;

	return L;
}

void freeLinkedList_h(linkedList_h* L) {
	listNode* tr;

	tr = L->head;
	
	while (tr != NULL) {
		L->head = tr->link;
		free(tr);
		tr = L->head;
	}
}

void printList(linkedList_h* L) {
	listNode* tr;

	tr = L->head;
	
	while (tr != NULL) {
		printf("%s ", tr->data);
		tr = tr->link;
	}
	printf("\n\n");
}

void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strncpy(newNode->data, x, DATA_SIZE);
	newNode->link = L->head;
	
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	strncpy(newNode->data, x, DATA_SIZE);

	if (L->head == NULL) {
		L->head = newNode;
		newNode->link = NULL;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* tr;

	newNode = (listNode*)malloc(sizeof(listNode));
	strncpy(newNode->data, x, DATA_SIZE);
	newNode->link = NULL;
	
	tr = L->head;

	if (tr == NULL) {
		tr = newNode;
		return;
	}

	while (tr->link != NULL)
		tr = tr->link;
	tr->link = newNode;
}
