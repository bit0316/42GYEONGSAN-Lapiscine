/*
* File name : Homework07_02.c
* Author : Kim Yeong Ho
* Date : July 31, 2023
* Major feature :
* - 영어 단어를 입력 받아서 입력받은 단어의 가운데 문자를 기준으로 좌우대칭인 단어는
    ‘좌우대칭인 단어입니다’ 아닌 경우 ‘좌우대칭인 단어가 아닙니다‘ 라고 결과를 출력하세요. 
*/
#include <stdio.h>

#define MAX_STRING_SIZE	100

int get_string_size(char s[]);
void get_string(char s[]);
void check_palindrome(const char s[]);

int main(void) {
	char string[MAX_STRING_SIZE];

	printf("문자열을 입력하세요 : ");
	get_string(string);

	check_palindrome(string);

	return 0;
}

int get_string_size(char s[]) {
	int count = 0;

	while (s[count] != '\n')
		count++;

	return count;
}

void get_string(char s[]) {
	for (int i = 0; i < MAX_STRING_SIZE; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\n')
			break;
	}
}

void check_palindrome(const char s[]) {
	int s_size = get_string_size(s);

	for (int i = 0; i < s_size / 2; i++) {
		if (s[i] == s[s_size - i - 1] && i < s_size / 2 - 1)
			continue;
		else if (s[i] != s[s_size - i - 1])
			printf("좌우대칭인 단어가 아닙니다.\n");
		else
			printf("좌우대칭인 단어입니다.\n");
		break;
	}
}
