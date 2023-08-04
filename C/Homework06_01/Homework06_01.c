/*
* File name : Homework06_01.c
* Author : Kim Yeong Ho
* Date : July 28, 2023
* Major feature :
* - 학생 10명의 성적을 입력 받아 배열 형식으로 저장하고 아래의 조건에 따라 값을 출력하시오.
*   - 입력받은 성적을 오름차순으로 정렬
*   - 성적의 평균과 분산을 계산하여 출력
*   - 평균과 분산은 다음과 같은 원형의 함수를 만들고, 배열을 입력으로 받아서 처리
*/
#include <stdio.h>
#include <math.h>

#define STUDENT_SIZE	10

int arr_size;
float cal_avg(int x[]);
float cal_var(int x[], float avg);
void get_score(int x[]);
void selection_sort(int x[]);
void print_score(const int x[], const float avg, const float var);

int main(void) {
	int score[STUDENT_SIZE];
	float avg, var;
	
	arr_size = sizeof(score) / sizeof(score[0]);
	printf("성적을 %d개 입력하시오 (크기, 순서 상관없음) : ", STUDENT_SIZE);
	get_score(score);
	
	selection_sort(score);
	avg = cal_avg(score);
	var = cal_var(score, avg);
	
	print_score(score, avg, var);

	return 0;
}
void get_score(int x[]) {
	for (int i = 0; i < STUDENT_SIZE; i++)
		scanf("%d", &x[i]);
}

float cal_avg(int x[]) {
	int sum = 0;
	float avg;

	for (int i = 0; i < arr_size; i++)
		sum += x[i];
	avg = (float)sum / arr_size;

	return avg;
}

float cal_var(int x[], float avg) {
	float sum = 0, var;

	for (int i = 0; i < arr_size; i++)
		sum += (x[i] - avg) * (x[i] - avg);
	var = sum / arr_size;

	return var;
}

void selection_sort(int x[]) {
	int min, temp;

	for (int i = 0; i < arr_size - 1; i++) {
		min = i;

		for (int j = i + 1; j < arr_size; j++)
			if (x[min] > x[j])
				min = j;

		if (min != i) {
			temp = x[i];
			x[i] = x[min];
			x[min] = temp;
		}
	}
}

void print_score(const int x[], const float avg, const float var) {
	printf("오름차순으로 정렬된 시험점수 : ");
	for (int i = 0; i < arr_size; i++)
		printf("%d ", x[i]);
	printf("\n");

	printf("시험 점수의 평균 : %.2f\n", avg);
	printf("시험 점수의 분산 : %.2f\n", var);
}
