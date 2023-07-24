/*
* File name : Homework02_01.c
* Author : Kim Yeong Ho
* Date : July 24, 2023
* Major feature :
* - 가진 돈을 입력 받아서 가방을 살 수 있는 경우의 수를 출력하시오.
*	- 가방은 종류별로 1개씩만 있다고 가정
*		가방	가격
*		A		25000
*		B		22000
*		C		31000
*/
#include <stdio.h>

int main(void)
{
	int priceA = 25000;
	int priceB = 22000;
	int priceC = 31000;
	int money;

	printf("가지고 있는 돈을 쓰시오 : ");
	scanf("%d", &money);

	printf("살 수 있는 경우의 수\n");
	(money >= priceA) ? printf("A\n") : printf("");
	(money >= priceB) ? printf("B\n") : printf("");
	(money >= priceC) ? printf("C\n") : printf("");
	(money >= priceA + priceB) ? printf("A와 B\n") : printf("");
	(money >= priceA + priceC) ? printf("A와 C\n") : printf("");
	(money >= priceB + priceC) ? printf("B와 C\n") : printf("");
	(money >= priceA + priceB + priceC) ? printf("A와 B와 C\n") : printf("");

	return 0;
}