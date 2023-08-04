/*
* File name : Homework08_01.c
* Author : Kim Yeong Ho
* Date : August 01, 2023
* Major feature :
* - 3X4행렬을 Matrix.txt파일에 저장 후 출력하기.
*   - 주의사항:
*   - 2차원 int 배열 사용
*   - 파일이 열리는지 확인할 것
*   - 행렬 출력 시 양수에는 +, 음수에는 –가 출력되게 할 것
*/
#include <stdio.h>

#define MAX_STRING_SIZE	100
#define MATRIX_ROW		3
#define MATRIX_COL		4

void get_file_mtrx(FILE* fp, int mtrx[][MATRIX_COL]);
void print_mtrx(const int mtrx[][MATRIX_COL]);

int main(void) {
	FILE* fp;
	char file_name[MAX_STRING_SIZE] = "Matrix.txt";
	int mtrx[MATRIX_ROW][MATRIX_COL];

	fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		exit(0);
	}
	else {
		printf("파일 열기 성공\n");
		get_file_mtrx(fp, mtrx);
		print_mtrx(mtrx);

	}
	fclose(fp);

	return 0;
}

void get_file_mtrx(FILE* fp, int mtrx[][MATRIX_COL]) {
	for (int i = 0; i < MATRIX_ROW; i++) {
		for (int j = 0; j < MATRIX_COL; j++) {
			fscanf(fp, "%d", &mtrx[i][j]);
		}
	}
}

void print_mtrx(const int mtrx[][MATRIX_COL]) {
	printf("행 : %d, 열 : %d, matrix 출력\n\n", MATRIX_ROW, MATRIX_COL);
	for (int i = 0; i < MATRIX_ROW; i++) {
		for (int j = 0; j < MATRIX_COL; j++) {
			printf("%+4d ", mtrx[i][j]);
		}
		printf("\n");
	}
}
