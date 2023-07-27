/*
* File name : Homework05_03.c
* Author : Kim Yeong Ho
* Date : July 27, 2023
* Major feature :
* - 학생 10명 이하의 성적을 키보드로 국어, 영어, 수학 순으로 작성하고 총점과 평균을 구하여라.
* - 자료를 저장하기 위한 배열을 먼저 선언하시오.
* - 몇 명의 학생이 시험을 보았는지 입력하시오.(자유 – 10명 이하)
* - 학생 별 국어, 영어, 수학 성적을 입력하시오.(자유 – 100점 이하)
* - 점수가 0보다 작거나 100보다 크다면 다시 입력하도록 하여라
* - 각 학생의 평균값을 히스토그램으로 * 를 사용하여 나타내어라.
* - 평균값의 소수점이 0.5이상이라면 반올림하여 히스토그램으로 나타내어라.
    예) 평균 : 3.57 **** 평균 : 3.26 ***
*/
#include <stdio.h>
#define STUDENTS_SIZE	10
#define SUBJECT_SIZE	3
#define MIN_SCORE		0
#define MAX_SCORE		100

int get_student();
void get_score(int student, int score[][SUBJECT_SIZE]);
void print_score(const int student, const int score[][SUBJECT_SIZE]);
void print_histogram(const float avg);

int main(void) {
	int student;
	int score[STUDENTS_SIZE][SUBJECT_SIZE];

	student = get_student();
	get_score(student, score);
	print_score(student, score);

	return 0;
}

int get_student() {
	int student;

	while (1) {
		printf("몇 명의 학생이 시험을 보았나요? : ");
		scanf("%d", &student);

		if (student < 0)
			printf("0 이상의 학생을 입력해주세요.\n");
		else if (student > 10)
			printf("%d 이하의 학생을 입력해주세요.\n", STUDENTS_SIZE);
		else
			return student;
	}
}

void get_score(int student, int score[][SUBJECT_SIZE]) {
	int index = 0, error;

	while (index < student) {
		printf("%d반 학생의 점수 : ", index + 1);

		error = 0;
		for (int i = 0; i < SUBJECT_SIZE; i++) {
			scanf("%d", &score[index][i]);

			if (score[index][i] < 0) {
				printf("%d 이상의 점수를 입력해주세요.\n", MIN_SCORE);
				error++;
			}
			else if (score[index][i] > 100) {
				printf("%d 이하의 점수를 입력해주세요.\n", MAX_SCORE);
				error++;
			}
		}

		if (error == 0)
			index++;
	}
}

void print_score(const int student, const int score[][SUBJECT_SIZE]) {
	int sum[STUDENTS_SIZE];
	float avg[STUDENTS_SIZE];

	for (int i = 0; i < STUDENTS_SIZE; i++) {
		sum[i] = 0;
		for (int j = 0; j < SUBJECT_SIZE; j++)
			sum[i] += score[i][j];
		avg[i] = (float)sum[i] / SUBJECT_SIZE;
	}

	printf("\n\n번호\t 국어\t 영어\t 수학\t 총점\t 평균\t 히스토그램\n");
	for (int i = 0; i < student; i++) {
		printf("%d\t ", i + 1);
		for (int j = 0; j < SUBJECT_SIZE; j++)
			printf("%d\t ", score[i][j]);
		printf("%d\t %.2f\t ", sum[i], avg[i]);
		print_histogram(avg[i]);
	}
}

void print_histogram(const float avg) {
	int count = (avg - (int)avg >= 0.5) ? avg / 1 + 1 : avg / 1;

	for (int i = 0; i < count; i++) {
		printf("*");
	}
	printf("\n");
}
