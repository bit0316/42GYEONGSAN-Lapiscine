/*
 * File name : Homework03_02.java
 * Author : Kim Yeong Ho
 * Date : July 12, 2023
 * Major feature : 
 * - 양의 정수를 10개를 입력받아 배열에 저장하고, 배열에 있는 정수 중에서 3의 배수만 출력하는 프로그램을 while문을 사용하여 작성하시오. 
 * - 양의 정수 10개를 입력하시오>>1 5 99 22 345 154 2346 55 32 85
 * - 3의 배수는 99 345 2346
 */
package Homework03_02;

import java.util.Scanner;

public class Homework03_02 {
	public static void main(String[] args) {
		final int count = 10;
		final int multiple = 3;
		int index = 0;
		int[] num = new int[count];
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("양의 정수를 " + count + "개를 입력하시오 : ");
		while (index < count) {
			num[index] = scanner.nextInt();
			index++;
		}
		
		index = 0;
		System.out.print(multiple + "의 배수는 ");
		while (index < count) {
			if (num[index] % multiple == 0) {
				System.out.print(num[index] + " ");
			}
			index++;
		}

		scanner.close();
	}
}
