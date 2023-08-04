/*
* File name : Homework07_01.c
* Author : Kim Yeong Ho
* Date : July 31, 2023
* Major feature :
* - 메인함수)
*   - 두 문자열을 입력 받으시오.
*   - 두 문자열 중 몇번째까지 비교할지 입력 받으시오.
* - 함수1)
*   - 두 문자열을 비교하여 문자열이 동일할 경우 “두 문자열은 동일합니다.”가 출력되고,
      첫번째 문자열이 클 경우 “첫번째 문자열이 큽니다.” 가 출력되고,
	  두번째 문자열이 클 경우 “두번째 문자열이큽니다.”다 출력되도록 설정하시오.
*     - (문자열 비교는 사전순으로 뒤에 있는 문자가 크다고 가정. Ex) A와 B중 B가 더 크다고 설정한다)
*     - (아스키 코드 순으로 비교해도 관계없음)
*/
#include <stdio.h>

#define MAX_STRING_SIZE	100

void get_string(char s[]);
void compare_strings(const char s1[], const char s2[]);

int main(void) {
	char string1[MAX_STRING_SIZE], string2[MAX_STRING_SIZE];

	printf("첫번째 문자열 입력 : ");
	get_string(string1);

	printf("두번째 문자열 입력 : ");
	get_string(string2);

	compare_strings(string1, string2);

	return 0;
}

void get_string(char s[]) {
	for (int i = 0; i < MAX_STRING_SIZE; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\n')
			break;
	}
}

void compare_strings(const char s1[], const char s2[]) {
	int compare_size;

	printf("몇글자까지 비교할까요? : ");
	scanf("%d", &compare_size);

	for (int i = 0; i < compare_size; i++) {
		if (s1[i] == s2[i] && i < compare_size - 1)
			continue;
		else if (s1[i] > s2[i])
			printf("첫번째 문자열이 큽니다.\n");
		else if (s1[i] < s2[i])
			printf("두번째 문자열이 큽니다.\n");
		else
			printf("두 문자열은 동일합니다.\n");
		break;
	}
	printf("-----------------------\n");
}
