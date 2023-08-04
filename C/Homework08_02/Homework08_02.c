/*
* File name : Homework08_02.c
* Author : Kim Yeong Ho
* Date : August 01, 2023
* Major feature :
* - 성적할 입력할 학생의 수를 입력받아서, 그 학생들의 이름, 국어 점수, 수학 점수, 영어 점수를 입력받아
    구조체에 저장 후, 각 과목의 최고 점수인 학생의 이름을 출력하는 프로그램을 만드시오.
* - 구조체 배열을 사용하시오
*/
#include <stdio.h>

#define MIN_STUDENT_SIZE	2
#define MAX_STUDENT_SIZE	10
#define MAX_NAME_SIZE		10

typedef struct student {
	char name[MAX_NAME_SIZE];
	int kor;
	int mat;
	int eng;
} Student;

int get_student_size();
void get_student_score(Student std[], const int std_size);
void print_best_score(const Student std[], const int std_size);
void print_best_kor_score(const Student std[], const int std_size);
void print_best_mat_score(const Student std[], const int std_size);
void print_best_eng_score(const Student std[], const int std_size);
void print_best_student(const Student std[], const int best_std[], const int std_size);

int main(void) {
	Student std[MAX_STUDENT_SIZE];
	int std_size;

	std_size = get_student_size();
	get_student_score(std, std_size);
	print_best_score(std, std_size);

	return 0;
}

int get_student_size() {
	int std_size;

	while (1) {
		printf("성적을 입력할 학생의 수 (%d ~ %d) : ", MIN_STUDENT_SIZE, MAX_STUDENT_SIZE);
		scanf("%d", &std_size);
		if (std_size >= 2 && std_size <= 10)
			return std_size;
		printf("다시 입력해주세요.\n");
	}
}

void get_student_score(Student s[], const int std_size) {
	for (int i = 0; i < std_size; i++) {
		printf("%d번 학생 이름 : ", i + 1);
		scanf("%s", s[i].name);
		printf("%s 학생의 국어 성적 : ", s[i].name);
		scanf("%d", &s[i].kor);
		printf("%s 학생의 수학 성적 : ", s[i].name);
		scanf("%d", &s[i].mat);
		printf("%s 학생의 영어 성적 : ", s[i].name);
		scanf("%d", &s[i].eng);
		printf("\n");
	}
}

void print_best_score(Student std[], const int std_size) {
	while (1) {
		printf("1. 국어 최고 점수\n");
		printf("2. 수학 최고 점수\n");
		printf("3. 영어 최고 점수\n");
		printf("4. 종료\n");

		switch (getch()) {
		case '1':	print_best_kor_score(std, std_size);	break;
		case '2':	print_best_mat_score(std, std_size);	break;
		case '3':	print_best_eng_score(std, std_size);	break;
		case '4':	return 0;								break;
		default:	printf("다시 입력해주세요.\n");			break;
		}
	}
}

void print_best_kor_score(const Student std[], const int std_size) {
	int best_score = 0, index = 0, best_std[MAX_STUDENT_SIZE];

	for (int i = 0; i < std_size; i++) {
		if (best_score < std[i].kor) {
			best_score = std[i].kor;
			index = 0;
			best_std[index] = i;
		}
		else if (best_score == std[i].kor) {
			best_std[++index] = i;
		}
	}

	print_best_student(std, best_std, index + 1);
	printf(" 학생이 %d점으로 국어 1등입니다.\n\n", best_score);
}

void print_best_mat_score(const Student std[], const int std_size) {
	int best_score = 0, index = 0, best_std[MAX_STUDENT_SIZE];
	for (int i = 0; i < std_size; i++) {
		if (best_score < std[i].mat) {
			best_score = std[i].mat;
			index = 0;
			best_std[index] = i;
		}
		else if (best_score == std[i].mat) {
			best_std[++index] = i;
		}
	}
	print_best_student(std, best_std, index + 1);
	printf(" 학생이 %d점으로 수학 1등입니다.\n\n", best_score);
}

void print_best_eng_score(const Student std[], const int std_size) {
	int best_score = 0, index = 0, best_std[MAX_STUDENT_SIZE];
	for (int i = 0; i < std_size; i++) {
		if (best_score < std[i].eng) {
			best_score = std[i].eng;
			index = 0;
			best_std[index] = i;
		}
		else if (best_score == std[i].eng) {
			best_std[++index] = i;
		}
	}
	print_best_student(std, best_std, index + 1);
	printf("학생이 %d점으로 영어 1등입니다.\n\n", best_score);
}

void print_best_student(const Student std[], const int best_std[], const int std_size) {
	for (int i = 0; i < std_size; i++) {
		if (i < std_size - 1)
			printf("%s, ", std[best_std[i]].name);
		else
			printf("%s ", std[best_std[i]].name);
	}
}
