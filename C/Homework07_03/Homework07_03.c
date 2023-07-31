/*
* File name : Homework07_03.c
* Author : Kim Yeong Ho
* Date : July 31, 2023
* Major feature :
* - ‘문자열’을 활용
* - 10칸의 char 배열을 선언하고 길이가 10인 문자열을 배열에 입력받아 저장한 뒤
    소문자, 대문자, 숫자, 특수기호 각각 구분 후, 각각의 개수 세기
* - 연산 후 그 결과를 출력한다.
*/
#include <stdio.h>

#define MAX_STRING_SIZE	10

void get_string(char s[]);
void print_character_analysis(const char s[]);

int main(void) {
	char string[MAX_STRING_SIZE];

	printf("문자열을 입력하세요 : ");
	get_string(string);

	print_character_analysis(string);

	return 0;
}

void get_string(char s[]) {
	for (int i = 0; i < MAX_STRING_SIZE; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\n')
			break;
	}
}

void print_character_analysis(const char s[]) {
	int upper = 0, lower = 0, number = 0, special = 0;

	for (int i = 0; i < MAX_STRING_SIZE; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			upper++;
		else if (s[i] >= 'a' && s[i] <= 'z')
			lower++;
		else if (s[i] >= '0' && s[i] <= '9')
			number++;
		else
			special++;
	}

	printf("대문자의 개수 : %d\n", upper);
	printf("소문자의 개수 : %d\n", lower);
	printf("숫자의 개수 : %d\n", number);
	printf("특수기호의 개수 : %d\n", special);
}
