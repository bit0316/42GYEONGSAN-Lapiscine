/*
* File name : Homework01_01.c
* Author : Kim Yeong Ho
* Date : July 21, 2023
* Major feature : 
* - 키와 몸무게를 입력 받아 키를 height에 저장하고, 몸무게를 weight에 저장하여 BMI지수를 계산 하는 프로그램을 작성하시오.
* - 단, 키는 cm단위로 입력 받은 후 m단위로 변환하시오.
* - BMI 지수는 실수 형태로 출력
* - cf) BMI지수 = 몸무게(kg) / 키(m)^2
*/
#include <stdio.h>

int main(void) {
	float height, weight, bmi;

	printf("BMI지수 계산기\n");

	printf("키를 입력하세요(cm) : ");
	scanf("%f", &height);

	printf("몸무게를 입력하세요(kg) : ");
	scanf("%f", &weight);

	bmi = weight / ((height * 0.01) * (height * 0.01));
	printf("BMI지수는 %f입니다.\n", bmi);

	return 0;
}
