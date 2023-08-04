/* doubleLinkedList.c */
#include "doubleLinkedList.h"

linkedList_h* createLinkedList_h(void) {
	linkedList_h* dl;

	dl = (linkedList_h*)malloc(sizeof(linkedList_h));
	dl->head = NULL;

	return dl;
}

void printList(linkedList_h* DL) {
	listNode* tr;

	tr = DL->head;

	while (tr != NULL) {
		printf("%s ", tr->data);
		tr = tr->rlink;
	}
	printf("\n\n");
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	
	strncpy(newNode->data, x, DATA_SIZE);

	if (pre == NULL) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DL->head = newNode;
	}
	else if (pre->rlink == NULL){
		newNode->llink = pre;
		newNode->rlink = pre->rlink;
		newNode->llink->rlink = newNode;
	}
	else {
		newNode->llink = pre;
		newNode->rlink = pre->rlink;
		newNode->llink->rlink = newNode;
		newNode->rlink->llink = newNode;
	}
}

void deleteNode(linkedList_h* DL, listNode* old) {
	if (DL->head == old) {
		DL->head = old->rlink;
		old->rlink->llink = NULL;
		free(old);
	}
	else if (old != NULL) {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);
	}
}

listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* tr;

	tr = DL->head;

	while (tr != NULL) {
		if (strncmp(tr->data, x, DATA_SIZE) == 0)
			return tr;
		else
			tr = tr->rlink;
	}
	return tr;
}
