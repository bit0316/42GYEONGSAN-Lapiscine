/*
* File name : Homework04_02.c
* Author : Kim Yeong Ho
* Date : July 26, 2023
* Major feature :
* - 사용자로부터 색깔의 종류의 개수를 입력 받아, 주어진 사각형의 4가지 영역을
*   아래의 조건을 만족하면서 채우는 모든 방법과 전체 가짓수를 찾아내는 프로그램을 작성하시오.
*   - 색깔의 종류의 개수는 2, 3, 4로 한정
*     - 색깔 2개: Red, Green
*     - 색깔 3개: Red, Green, Blue
*     - 색깔 4개: Red, Green, Blue, Yellow
*   - 인접한 영역은 동일한 색깔을 가질 수 없음
*   - 조건을 만족하는 4가지 영역 coloring 예시:
*     (1) : Red		(2) : Green
*     (3) : Blue	(4) : Yellow
*/
#include <stdio.h>

int count_color(int a, int b, int c, int d);
void print_color(int num, int order);

int main(void) {
	int num, order, index = 0, count = 0;

	printf(" - number of colors (2 ~ 4): ");
	scanf("%d", &num);

	for (int a = 0; a < num; a++) {
		for (int b = 0; b < num; b++) {
			for (int c = 0; c < num; c++) {
				for (int d = 0; d < num; d++) {
					if (a != b && a != c && b != d && c != d) {
						order = 1;	count++;
						printf(" %4d:", count);
						print_color(a, order++);
						print_color(b, order++);
						print_color(c, order++);
						print_color(d, order);
						printf(" # of colors = %d", count_color(a, b, c, d));
						printf("\n");
					}
				}
			}
		}
	}
	printf(" - Total number of coloring: %d\n", count);

	return 0;
}

int count_color(int a, int b, int c, int d) {
	int index = 0;

	for (int i = 0; i < 4; i++)
		if (a == i || b == i || c == i || d == i)
			index++;

	return index;
}

void print_color(int num, int order) {
	switch (num) {
		case 0: printf(" (%d):    Red ", order);	break;
		case 1: printf(" (%d):  Green ", order);	break;
		case 2: printf(" (%d):   Blue ", order);	break;
		case 3: printf(" (%d): Yellow ", order);	break;
		default: printf(" (%d): Error ", order);	break;
	}
}