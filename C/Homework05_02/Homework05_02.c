/*
* File name : Homework05_02.c
* Author : Kim Yeong Ho
* Date : July 27, 2023
* Major feature :
* - 배열선언 초기화를 이용하여 합과 평균 출력
* - 배열score를 선언하고 6개 점수를 저장한 다음 시험 성적의 합, 평균을 구하시오.
*/
#include <stdio.h>

#define SCORE_SIZE	6
#define MIN_SCORE	0
#define MAX_SCORE	100

int main(void) {
	float score[SCORE_SIZE];
	int sum = 0, index = 0;
	float avg;

	while (index < SCORE_SIZE) {
		printf("score[%d] = ", index);
		scanf("%f", &score[index]);

		if (score[index] < MIN_SCORE || score[index] > MAX_SCORE) {
			printf("입력된 값은 유효하지 않습니다. 다시 입력해주세요.\n\n");
			continue;
		}

		sum += score[index++];
	}
	avg = (float)sum / SCORE_SIZE;

	printf("성적의 합은 %d, 평균은 %.1f입니다.", sum, avg);

	return 0;
}
