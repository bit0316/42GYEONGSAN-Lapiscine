/*
* File name : Homework08_03.c
* Author : Kim Yeong Ho
* Date : August 01, 2023
* Major feature :
* - 텍스트파일을 읽어 화면에 출력하는 프로그램을 작성하시오. 
*   - 프로그램이 실행되면 텍스트파일의 이름을 묻고,
*   - 파일이 존재하지 않으면 ‘파일 (파일이름)을 열 수 없습니다’ 출력 후 종료하며,
*   - 파일이 존재하면 파일의 내용을 화면에 출력
*/
#include <stdio.h>

#define MAX_STRING_SIZE	100

void get_file_name(char file_name[]);
void print_file_text(const FILE* fp);

int main(void) {
	FILE* fp;
	char file_name[MAX_STRING_SIZE];

	get_file_name(file_name);
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("파일 %s 열기 실패\n", file_name);
		exit(0);
	}
	else {
		printf("파일 %s 열기 성공\n", file_name);
		print_file_text(fp);
	}

	fclose(fp);

	return 0;
}

void get_file_name(char file_name[]) {
	printf("파일명을 입력하세요. : ");
	scanf("%s", file_name);
}

void print_file_text(const FILE* fp) {
	char ch;

	printf("\n");
	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	printf("\n");
}
