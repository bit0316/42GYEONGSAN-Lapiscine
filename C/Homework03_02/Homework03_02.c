/*
* File name : Homework03_02.c
* Author : Kim Yeong Ho
* Date : July 25, 2023
* Major feature :
* - 1 이상의 정수를 입력 받아 피라미드를 생성하는 프로그램을 만드세요
*  - 입력 값은 1 이상의 정수로 높이를 나타냅니다
*  - 입력은 최대 20까지 입력하도록 합니다
*    - 0 이하 또는 20 초과의 값을 입력할 경우 허용된 값을 벗어났다는 메시지를 출력하게 합니다
*   - 피라미드 모양은 이등변 삼각형 모양으로 출력하세요
*   - 각 층은 1부터 이전 층의 마지막 수에 2를 더한 값 만큼 순서대로 출력합니다 ([2 * 해당 층 높이 – 1]까지 출력)
*   - 첫 번째 층은 1만 출력합니다
*/
#include <stdio.h>

int main(void) {
	int floor, index;

	printf("피라미드의 층 수를 입력하세요 : ");
	scanf("%d", &floor);

	if (floor > 0 || floor <= 20) {
		for (int i = 1; i <= floor; i++) {
			index = 1;

			for (int j = 1; j < floor + i; j++) {
				if (floor - i >= j) {
					printf("   ");
				}
				else {
					printf("%3d", index++);
				}
			}
			printf("\n");
		}
	}
	else {
		printf("허용된 입력을 벗어났습니다.\n");
	}

	return 0;
}