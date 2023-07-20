/*
 * File name : Homework01_01.java
 * Author : Kim Yeong Ho
 * Date : July 10, 2023
 * Major feature : 
 * - Scanner 클래스를 이요하여 원화를 입력받아 달러로 바꾸는 다음 예시와 같이 출력하는 프로그램을 작성하시요.
 * - 1달러는 1200원으로 가정하여 환산하길 바랍니다. 
 * - 원화를 입력하세요(단위 원) >> 3600
 * - 3600원은 $3.0 달러 입니다.
 */
package Homework01_01;

import java.util.Scanner;

public class Homework01_01 {
	public static void main(String[] args) {
		int krw;
		float usd;
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("원화를 입력하세요(단위 원) : ");
		krw = scanner.nextInt();		
		usd = krw / 1200f;
		System.out.println(krw + "원은 $" + usd + "달러 입니다.");

		scanner.close();
	}
}
