/*
* File name : Homework06_03.c
* Author : Kim Yeong Ho
* Date : July 28, 2023
* Major feature :
* - 포인터를 이용한 버블정렬 구현
* - 10칸의 int 배열을 선언하고 10개의 정수를 배열에 입력 받아 저장한 뒤 버블정렬을 이용해 오름차순으로 정렬하라.
* - 정렬 후 그 결과를 출력한다.
* - ※ 유의사항
*   - 배열은 선언 이후 인덱스([])를 사용하면 안되며 포인터를 이용한다.
*   - 정렬은 bubble_sort(int* arr), 정렬 함수 내부에서 정수 간의 교환은
*     swap(int* a, int* b) 함수를 이용하여 코드를 작성한다.
*/
#include <stdio.h>

#define ARRAY_SIZE	10

void get_array(int* arr);
void print_array(int* arr);
void bubble_sort(int* arr);
void swap(int* a, int* b);

int main(void) {
	int arr[ARRAY_SIZE];

	get_array(arr);
	bubble_sort(arr);

	printf("버블 정렬 이후 : ");
	print_array(arr);

	return 0;
}

void get_array(int* arr) {
	printf("정렬하려는 정수를 %d개 입력하시오 : ", ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++)
		scanf("%d", (arr + i));
}

void print_array(int* arr) {
	for (int i = 0; i < ARRAY_SIZE; i++)
		printf("%d ", *(arr + i));
}

void bubble_sort(int* arr) {
	for (int i = 1; i < ARRAY_SIZE; i++)
		for (int j = 0; j < ARRAY_SIZE - i; j++)
			if (*(arr + j) > *(arr + j + 1))
				swap(arr + j, arr + j + 1);
}

void swap(int* a, int* b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
