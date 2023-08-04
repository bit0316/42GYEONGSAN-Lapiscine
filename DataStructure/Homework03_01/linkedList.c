/* linkedList.c */
#include "linkedList.h"

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
		L->head = newNode;
		return;
	}

	while (tr->link != NULL)
		tr = tr->link;
	tr->link = newNode;
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* tr;
	
	tr = L->head;
	
	while (tr->link != p)
		tr = tr->link;
	tr->link = NULL;
	free(p);
}

listNode* searchNode(linkedList_h* L, char* x) {
	listNode* tr;

	tr = L->head;

	while (tr != NULL) {
		if (strncmp(tr->data, x, DATA_SIZE) == 0)
			return tr;
		else
			tr = tr->link;
	}
	return tr;
}

void reverse(linkedList_h* L) {
	listNode* old;
	listNode* tr;
	listNode* pre;
	
	old = L->head;
	tr = old->link;
	pre = tr->link;

	old->link = NULL;
	while (pre != NULL) {
		tr->link = old;
		old = tr;
		tr = pre;
		pre = pre->link;
	}
	tr->link = old;
	L->head = tr;
}
