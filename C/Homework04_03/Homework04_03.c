/*
* File name : Homework04_03.c
* Author : Kim Yeong Ho
* Date : July 26, 2023
* Major feature :
* - a부터 z까지 소문자 알파벳 가운데 하나를 입력 받아,
*   그 알파벳부터 순서대로 화면에 이동하면서 출력하는 프로그램을 작성하시오.
*   - 알파벳 소문자가 아닌 경우에는 입력을 다시 받음!
*   - 한 줄에 문자를 50번 출력하면, 다음 줄로 넘어가서 출력
*   - z 다음에는 a로 돌아가서 다시 순차적으로 출력하고, 이 작업을 무한번 반복
*   - 반복이 되는 도중 키보드 입력이 있으면(예를 들면 space key),
*     반복을 중지하고 프로그램 종료 (hint  Chap. 7)
*   - main() 함수에서는 알파벳이 출력될 위치 (x, y)를 계산하고,
*     다음과 같은 원형의 함수를 호출하여 화면에 원하는 알파벳(a)을 표시해야 함. 
*/
#include <stdio.h>
#include <conio.h>

#define LINE_SIZE		50
#define ALPHABET_SIZE	26

char get_alpha();
void print_alpha(int x, int y, char a);

int main(void) {
	int row, col, count = 0;
	char alpha;

	alpha = get_alpha();

	while (!_kbhit()) {
		alpha = (alpha > 'z') ? alpha - ALPHABET_SIZE : alpha;
		row = count / LINE_SIZE;
		col = count % LINE_SIZE;
		count++;

		print_alpha(col, row, alpha++);
	}

	return 0;
}

char get_alpha() {
	char alpha;

	while (1) {
		printf("알파벳을 입력하시오 (a ~ z) : ");
		scanf(" %c", &alpha);

		if (alpha < 'a' || alpha > 'z')
			printf("알파벳 소문자를 입력해야 합니다.\n");
		else
			return alpha;
	}
}

void print_alpha(int x, int y, char a) {
	char input = a - (x + LINE_SIZE * y) % ALPHABET_SIZE;
	input = (input < 'a') ? input + 26 : input;

	system("cls");
	printf("알파벳을 입력하시오 (a ~ z) : %c\n", input);
	for (int i = 0; i < y; i++)		printf("\n");
	for (int i = 0; i < x; i++)		printf(" ");
	printf("%c", a);

	Sleep(100);
}
