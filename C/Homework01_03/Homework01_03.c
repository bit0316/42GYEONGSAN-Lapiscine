/*
* File name : Homework01_03.c
* Author : Kim Yeong Ho
* Date : July 21, 2023
* Major feature :
* - 컴퓨터가 1 ~ 5범위의 난수(random number)를 생성하면 사용자가 그 숫자를 맞추는 게임을 만들고자 한다.
* - 사용자가 추측한 숫자가 더 크면 “UP”, 더 작으면 “DOWN”, 맞으면 “HIT”에 해당하는 메시지가 나오도록 프로그램을 작성하시오.
*   - 게임은 1번만 실행하고 종료.
* - 제한사항
*   - 수업 시간에 배운 C 문법만을 사용할 수 있음.
*     (즉, 조건문, 반복문, 배열 등을 사용할 수 없음.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int random_num, user_input, result;
	int min = 1, max = 5;

	srand((unsigned)time(NULL));
	random_num = 1 + rand() % max;

	printf("[UP-DOWN 게임] %d ~ %d 범위의 정수를 입력하시오 : ", min, max);
	scanf("%d", &user_input);

	printf("==============================\n");
	printf("random_num = %d, user_input = %d\n\n", random_num, user_input);

	result = (user_input + max) / (random_num + max) + (user_input + max) / (random_num + max + 1);
	printf("결과는 %d 입니다.\n", result);
	printf("( 0 은 down,\n  1 은 hit,\n  2 는 up )\n");

	return 0;
}
