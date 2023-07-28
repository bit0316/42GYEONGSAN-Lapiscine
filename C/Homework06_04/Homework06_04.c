/*
* File name : Homework06_04.c
* Author : Kim Yeong Ho
* Date : July 28, 2023
* Major feature :
* - 메뉴 선택에 따라 동작하는 간이 스택을 구현하라
*   - 배열 주소 이외에는 배열을 직접 참조할 수 없음
*   - 각 함수의 데이터타입은 void 이어야 함
* - 구현 필수 함수
*   - void pop(int *a)
*   - void push(int *a)
*   - void dump(int *a)
*/
#include <stdio.h>

#define ARRAY_SIZE	100

int top;
void print_menu();
void init(int* a);
void push(int* a);
void pop(int* a);
void dump(int* a);

int main(void) {
	int input, arr[ARRAY_SIZE];

	init(arr);

	while (1) {
		print_menu();
		scanf("%d", &input);

		switch (input) {
			case 1: push(arr);							break;
			case 2: pop(arr);							break;
			case 3: dump(arr);							break;
			case 4:	return 0;							break;
			default: printf("다시 입력해 주십시오.\n");	break;
		}
		printf("\n");
	}

	return 0;
}

void print_menu() {
	printf("1. 데이터 입력받기\n");
	printf("2. 데이터 빼기\n");
	printf("3. 전체 데이터 출력하기\n");
	printf("4. 종료하기\n");
	printf("메뉴선택 : ");
}

void init(int* a) {
	top = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
		*a++ = NULL;
}

void push(int* a) {
	printf("스택에 넣을 데이터를 입력하세요 : ");
	scanf("%d", a + top);
	top++;
}

void pop(int* a) {
	printf("pop 된 데이터 : %d\n", *(a + top));
	*(a + top) = NULL;
	top--;
}

void dump(int* a) {
	printf("dump data = ");
	for (int i = 0; i < top; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}
