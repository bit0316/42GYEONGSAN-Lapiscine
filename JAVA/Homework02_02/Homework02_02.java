/*
 * File name : Homework02_02.java
 * Author : Kim Yeong Ho
 * Date : July 11, 2023
 * Major feature : 
 * - 숫자를 입력받아 3~5는 "봄", 6~8은 "여름", 9~11은 "가을",
 * - 12~2는 "겨울"로, 그 이외의 숫자를 입력한 경우에는 "잘못입력"을 출력하는 프로그램을 작성하시오
 * - 달을 입력하시오(1~12)>>9
 * - 가을
 */
package Homework02_02;

import java.util.Scanner;

public class Homework02_02 {
	public static void main(String[] args) {
		final String[] seasons = {"겨울", "봄", "여름", "가을", "겨울"};
		int month;
		String result;
		Scanner scanner = new Scanner(System.in);

		System.out.print("달을 입력하시오(1~12) : ");
		month = scanner.nextInt();

		result = (0 < month && month < 13) ? seasons[month / 3] : "잘못입력";
		System.out.println(result);

		scanner.close();
	}
}
