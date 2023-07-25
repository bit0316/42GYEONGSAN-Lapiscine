/*
* File name : Homework03_03.c
* Author : Kim Yeong Ho
* Date : July 25, 2023
* Major feature :
* - 컴퓨터는 사용자가 알지 못하게 [1, 10] 범위의 난수(random number)를 5개 생성한다.
*   사용자가 [1, 10] 범위의 숫자 5개를 입력하면, 사용자가 입력한 숫자들과 컴퓨터가 생성한 숫자들 사이에
    일치하는 숫자의 개수를 출력하는 프로그램을 작성하시오.
*  - 컴퓨터가 생성하는 5개의 숫자들 가운데 중복 발생 가능
*  - 사용자가 입력하는 5개의 숫자들 가운데 중복 허용
*- 제한사항
*  - 이론 수업 시간에 배운 C 문법만을 사용할 수 있음.
      (즉, 배열 등을 사용할 수 없음.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rangeMin = 1, rangeMax = 10, count = 5;
    int input1, input2, input3, input4, input5;
    int rand1, rand2, rand3, rand4, rand5;
    int correct = 0;

    srand((unsigned)time(NULL));
    rand1 = rand() % 10 + 1;
    rand2 = rand() % 10 + 1;
    rand3 = rand() % 10 + 1;
    rand4 = rand() % 10 + 1;
    rand5 = rand() % 10 + 1;

    printf("=== Simple Lotto Game ===\n\n");

    printf("[%d, %d] 범위의 정수 %d개를 입력하시오 : ", rangeMin, rangeMax, count);
    scanf("%d %d %d %d %d", &input1, &input2, &input3, &input4, &input5);

    printf("컴퓨터가 생성한 [%d, %d] 범위의 난수 %d개 :", rangeMin, rangeMax, count);
    printf("%2d %2d %2d %2d %2d\n", rand1, rand2, rand3, rand4, rand5);

    for (int j = rangeMin; j <= rangeMax; j++) {
        if ((j == input1 || j == input2 || j == input3 || j == input4 || j == input5)
            && (j == rand1 || j == rand2 || j == rand3 || j == rand4 || j == rand5)) {
            correct++;
        }
    }

    printf("\n==> 일치한 숫자의 개수 : %d\n", correct);

	return 0;
}