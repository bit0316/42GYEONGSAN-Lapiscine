/*
* File name : Homework03_01.c
* Author : Kim Yeong Ho
* Date : July 25, 2023
* Major feature :
* - 정수형 연도를 입력 받아 윤년인지 아닌지 판별하는 프로그램.
*   - 윤년은 4년마다 2월이 29일까지 있는 해
*   - 연도가 4의 배수이면서 100의 배수가 아니거나 400의 배수여야 윤년.
*   - 윤년이 아니면 다음 윤년까지 몇 년 남았는지 출력해야 함.
*/
#include <stdio.h>

int main(void) {
	int year, remain;

	printf("연도를 입력하세요 : ");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		printf("윤년입니다.\n");
	}
	else {
		remain = (year % 100 == 0) ? 4 : 4 - year % 4;
		printf("윤년까지 %d년 남았습니다.\n", remain);
	}

	return 0;
}
