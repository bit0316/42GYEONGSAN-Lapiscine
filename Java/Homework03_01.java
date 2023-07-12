/*
 * File name : Homework03_01.java
 * Author : Kim Yeong Ho
 * Date : July 12, 2023
 * Major feature : 
 * - Scanner를 이용하여 정수를 입력받고 다음과 같이 *를 출력하는 for문을 사용하여 프로그램을 작성하시오. 
 * - 정수를 입력하시오>>5
 * - *****
 * - ****
 * - ***
 * - **
 * - *
 */
import java.util.Scanner;

public class Homework03_01 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("정수를 입력하시오 : ");
		int count = scanner.nextInt();
		
		for (int i = 0; i < count; i++) {
			for (int j = count; j > i; j--) {
				System.out.print("*");
			}
			System.out.println();
		}
		
		scanner.close();
	}
}
