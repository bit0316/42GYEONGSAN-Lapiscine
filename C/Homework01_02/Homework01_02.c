/*
* File name : Homework01_02.c
* Author : Kim Yeong Ho
* Date : July 21, 2023
* Major feature :
* - 세 개의 정수를 입력받아 A,B,C에 저장하고 A,B,C의 합은 sum, 평균은 average에 저장합니다.
*   세 개의 정수의 합과 평균을 구하여 각각 출력하는 프로그램을 작성하시오.
*   (평균을 나타낼 때, 소수점 한 자리까지 표시하려면 평균:%0.1f\n로 나타냄.)
* - 형 변환(type casting) 방법 : 선언된 변수 앞에 변환하고자 하는 형식을 ()안에 작성하고 이 ()는 변수 앞에 선언되어야 한다.
*   - ex)
*     - int x;
*     - float y = (float) x;
*/
#include <stdio.h>

int main(void) {
	int a, b, c, sum;
	float avg;

	printf("첫번째 숫자를 입력하시오 : ");
	scanf("%d", &a);

	printf("두번째 숫자를 입력하시오 : ");
	scanf("%d", &b);

	printf("세번째 숫자를 입력하시오 : ");
	scanf("%d", &c);

	sum = a + b + c;
	avg = sum / 3;
	printf("합 : %d\n", sum);
	printf("평균 : %.1f\n", avg);

	return 0;
}
