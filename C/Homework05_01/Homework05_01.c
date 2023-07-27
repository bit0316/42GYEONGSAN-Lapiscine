/*
* File name : Homework05_01.c
* Author : Kim Yeong Ho
* Date : July 27, 2023
* Major feature :
* - n과 a를 입력 받아 서로 다른 n개의 공 중에서 a개를 뽑는 경우의 수를 세번 구하고 출력하고,
* - 나온 경우의 수 결과값을 모두 더하는 변수 sum을 구하여 출력한다.
*   - n이 음수 혹은 0일 때, r이 n보다 클 때 다시 입력하도록 할 것.
*   - (sum)변수를 전역변수로 선언하고 (sum)변수를 main()함수에서 초기화하여 사용할 것.
*   - 경우의 수를 구하는 함수는 다음의 순환 함수를 이용할 것.
*   - 함수는 함수의 원형을 선언하여 문제를 풀 것.
*/
#include <stdio.h>

#define CHANCE_SIZE	3

int combination(int x, int y);

int sum;

int main(void) {
	int ballCount, pickCount;
	int order = 0, result;

	sum = 0;
	while (order < CHANCE_SIZE) {
		printf("%d번째 경우에서의 총 공의 개수와 뽑을 공의 개수를 입력하세요 : ", order + 1);
		scanf("%d %d", &ballCount, &pickCount);

		if (ballCount < 1 || ballCount < pickCount) {
			printf("입력된 값은 유효하지 않습니다. 다시 입력해주세요.\n\n");
			continue;
		}

		result = combination(ballCount, pickCount);
		printf("%d번째 경우에서 %d개 중 %d개를 뽑는 경우의 수는 %d가지 입니다.\n", order + 1, ballCount, pickCount, result);

		sum += result;
		order++;
	}
	printf("모든 경우의 수의 합은 %d입니다.\n", sum);

	return 0;
}

int combination(int x, int y) {
	if (x == y || y == 0)
		return 1;
	else
		return combination(x - 1, y - 1) + combination(x - 1, y);
}
