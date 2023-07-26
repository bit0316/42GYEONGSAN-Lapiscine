/*
* File name : Homework04_01.c
* Author : Kim Yeong Ho
* Date : July 26, 2023
* Major feature :
* - 2개의 시간을 초 단위로 입력 받아서 일, 시, 분, 초 단위로 나누어 출력하세요
* - 2개의 입력된 시간의 차이 또한 일, 시, 분, 초 단위로 나누어 출력하세요
*   - 시간은 0 이상의 정수로 음수가 입력될 경우 다시 입력하도록 합니다
*   - 입력 값을 일, 시, 분, 초로 변환하여 출력하는 함수를 만드세요
*   - 두 입력 값의 차이를 구하는 함수를 만드세요
*   - 차이를 구하는 함수에서의 출력은 시간 변환 함수를 불러와서 출력하게 합니다
*   - 함수는 함수의 원형을 선언하여 문제를 풀어주시기 바랍니다(강의자료 8장 참조)
*   - 하루는 24시간, 1시간은 60분, 1분은 60초입니다
*/
#include <stdio.h>

void convert_seconds(int sec);
void time_diff(int sec1, int sec2);

int main(void) {
	int sec1, sec2;

	while (1) {
		printf("첫번째 초를 입력하세요 : ");
		scanf(" %d", &sec1);

		if (sec1 <= 0)
			printf("시간은 0보다 커야합니다.\n"); 
		else
			break;
	}

	while (1) {
		printf("두번째 초를 입력하세요 : ");
		scanf(" %d", &sec2);

		if (sec2 <= 0)
			printf("시간은 0보다 커야합니다.\n");
		else
			break;
	}

	printf("첫번째 시간은 ");
	convert_seconds(sec1);

	printf("두번째 시간은 ");
	convert_seconds(sec2);

	printf("두 입력된 시간의 차이는 ");
	time_diff(sec1, sec2);

	return 0;
}

void convert_seconds(int sec) {
	int day, hour, minute, second;

	second = sec % 60;
	minute = (sec / 60) % 60;
	hour = (sec / 60 / 60) % 24;
	day = sec / 60 / 60 / 24;

	printf("%d일 %2d시 %2d분 %2d초입니다. (%d초)\n", day, hour, minute, second, sec);
}

void time_diff(int sec1, int sec2) {
	if (sec1 > sec2)	convert_seconds(sec1 - sec2);
	else				convert_seconds(sec2 - sec1);
}
