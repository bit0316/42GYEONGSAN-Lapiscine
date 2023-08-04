/* doubleLinkedList.h */
#pragma once
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE	4

typedef struct ListNode {
	char data[DATA_SIZE];
	struct ListNode* llink;
	struct ListNode* rlink;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);
