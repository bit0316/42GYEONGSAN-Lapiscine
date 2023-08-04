/*
* File name : Homework02_02.c
* Author : Kim Yeong Ho
* Date : July 24, 2023
* Major feature :
* - 정수 1개를 입력(a)하고, 4를 몇 번 곱할 것인지 입력(p)하세요
* - 입력된 정수에 4를 입력한 만큼 곱한 값 10진수로 우선 출력하세요
*  - a x 4^p 계산 결과가 되어야 합니다
*   - 입력 a에 4^p를 곱하는 곱셈 연산은 반드시 비트연산자를 이용하세요
*   - 나온 값을 16진수를 출력할 때 앞에 0x를 붙여주세요
*     - ex) 0x0, 0x1CFF, 0x22 등등 자리 수는 무관합니다.
*/
#include <stdio.h>

int main(void)
{
	int input, times, result;

	printf("정수를 입력하시오 : ");
	scanf("%d", &input);

	printf("4을(를) 곱하고 싶은 횟수 : ");
	scanf("%d", &times);

	result = input * (4 << (times - 1) * 2);
	printf("%d x 4^%d = %d\n", input, times, result);
	printf("16진수로 변환한 값 : 0x%X", result);
	return 0;
}