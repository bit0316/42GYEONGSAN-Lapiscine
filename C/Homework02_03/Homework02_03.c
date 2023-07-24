/*
* File name : Homework02_03.c
* Author : Kim Yeong Ho
* Date : July 24, 2023
* Major feature :
* - 콩을 다음과 같이 4가지 서로 다른 크기의 그릇에 나누어 담고자 한다:
*  - 그릇-1은 콩 2개
*   - 그릇-2는 콩 3개
*  - 그릇-3은 콩 4개
*  - 그릇-4는 콩 6개를 담는다.
* - 콩이 N (1 <= N <=15)개 있을 때, 가능한 많은 그릇에 콩을 공평하게 분배하는 방법을 찾아
*   그 방식에 따라 그릇별로 배정된 콩의 개수를 출력하는 프로그램을 작성하시오.
*  - 하나의 콩을 담을 수 있는 그릇이 여러 개 있을 때는 그릇의 크기가 클 수록 우선 순위를 가짐
*  - 종류별 그릇의 개수는 1개로 가정
*  - 지금까지 배운 내용만을 이용할 것 (예를 들면, 조건문 등 사용불가)
*/
#include <stdio.h>

int main(void) {
	int bowlSizeA = 2, countA;
	int bowlSizeB = 3, countB;
	int bowlSizeC = 4, countC;
	int bowlSizeD = 6, countD;
	int bowlsCount = 4;
	int count;

	printf("콩의 개수를 입력하시오 (1 ~ 15) : ");
	scanf("%d", &count);

	countA = (count / bowlsCount < bowlSizeA) ? count / bowlsCount : bowlSizeA;
	count -= countA;
	bowlsCount--;

	countB = (count / bowlsCount < bowlSizeB) ? count / bowlsCount : bowlSizeB;
	count -= countB;
	bowlsCount--;

	countC = (count / bowlsCount < bowlSizeC) ? count / bowlsCount : bowlSizeC;
	count -= countC;
	bowlsCount--;

	countD = count;

	printf("그릇-1 콩의 개수(2) : %d\n", countA);
	printf("그릇-2 콩의 개수(3) : %d\n", countB);
	printf("그릇-3 콩의 개수(4) : %d\n", countC);
	printf("그릇-4 콩의 개수(6) : %d\n", countD);

	return 0;
}