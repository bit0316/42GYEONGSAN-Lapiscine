/*
* File name : Homework06_02.c
* Author : Kim Yeong Ho
* Date : July 28, 2023
* Major feature :
* - 함수1) 학생 5명 각자의 평균을 구하는 함수를 만드시오.
* - 함수2) 국어, 영어, 수학 각 과목들의 평균을 구하는 함수를 만드시오.
* - 메인함수)
*   - 학생 5명의 국어, 영어, 수학 점수가 들어갈 수 있는 배열을 만드시오.
      (단, 실수 출력 시 소수점 2번째 자리까지 출력하기, 학생별 배열 3칸의 순서는 국어, 영어, 수학 순서대로.
      국어 영어 수학 점수의 범위는 0-100점을 벗어나면 “잘못된 입력입니다” 출력 후 점수 입력 받기 재 실행시키기)
*   - 학생 5명의 국어 영어 수학 점수를 차례로 입력 받으시오.
*   - 학생 5명 각자의 평균을 구하는 함수(함수1)를 사용하여 학생별 평균을 구하고,
      main()함수에서 출력하십시오.
*   - 과목별로 평균을 구하는 함수(함수2)를 사용하여 과목별 평균을 구하고,
      main()함수에서 출력하십시오.
*/
#include <stdio.h>

#define STUDENT_SIZE    5
#define SUBJECT_SIZE	3
#define MIN_SCORE		0
#define MAX_SCORE		100

void get_score(float score[][SUBJECT_SIZE]);
void get_std_avg(float score[][SUBJECT_SIZE], float std_avg[]);
void get_sbj_avg(float score[][SUBJECT_SIZE], float sbj_avg[]);

int main(void) {
	float score[STUDENT_SIZE][SUBJECT_SIZE], std_avg[STUDENT_SIZE], sbj_avg[SUBJECT_SIZE];

	get_score(score);
	get_std_avg(score, std_avg);
	get_sbj_avg(score, sbj_avg);

	for (int i = 0; i < STUDENT_SIZE; i++)
		printf("std_%d의 평균 점수 : %.2f\n", i, std_avg[i]);
	printf("국어의 평균 점수 : %.2f\n", sbj_avg[0]);
	printf("영어의 평균 점수 : %.2f\n", sbj_avg[1]);
	printf("수학의 평균 점수 : %.2f\n", sbj_avg[2]);

	return 0;
}

void get_score(float score[][SUBJECT_SIZE]) {
	int index = 0, error = 0;

	while (index < STUDENT_SIZE) {
		printf("std_%d의 국어, 영어, 수학 점수를 입력하시오 (0 ~ 100) : ", index + 1);

		for (int i = 0; i < SUBJECT_SIZE; i++) {
			scanf("%f", &score[index][i]);

			if (score[index][i] < MIN_SCORE || score[index][i] > MAX_SCORE)
				error++;
		}
		index++;

		if (index == STUDENT_SIZE && error != 0) {
			printf("입력된 값은 유효하지 않습니다. 다시 입력해주세요.\n");
			index = 0;
			error = 0;
		}
	}
}

void get_std_avg(float score[][SUBJECT_SIZE], float std_avg[]) {
	float sum;

	for (int i = 0; i < STUDENT_SIZE; i++) {
		sum = 0;
		for (int j = 0; j < SUBJECT_SIZE; j++)
			sum += score[i][j];
		std_avg[i] = sum / SUBJECT_SIZE;
	}
}

void get_sbj_avg(float score[][SUBJECT_SIZE], float sbj_avg[]) {
	float sum = 0;

	for (int i = 0; i < SUBJECT_SIZE; i++) {
		sum = 0;
		for (int j = 0; j < STUDENT_SIZE; j++)
			sum += score[j][i];
		sbj_avg[i] = sum / STUDENT_SIZE;
	}
}
