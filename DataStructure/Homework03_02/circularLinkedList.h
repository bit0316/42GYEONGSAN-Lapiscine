/* circularLinkedList.h */
#pragma once
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE	4

typedef struct ListNode {
	char data[DATA_SIZE];
	struct ListNode* link;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* CL);
void insertFirstNode(linkedList_h* CL, char* x);
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x);
void deleteNode(linkedList_h* CL, listNode* p);
listNode* searchNode(linkedList_h* CL, char* x);
