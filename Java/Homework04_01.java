/*
 * File name : Homework04_01.java
 * Author : Kim Yeong Ho
 * Date : July 13, 2023
 * Major feature : 
 * - 아래와 같이 1부터 99까지 반복문을 이용하여 369 게임에서 박수를 쳐야 하는 경우를 순서대로 화면에 출력하는 프로그램을 작성하시오.
 * - 3 박수 짝
 * - 6 박수 짝
 * - 9 박수 짝
 * - 13 박수 짝
 * - 16 박수 짝
 * - 19 박수 짝
 */
public class Homework04_01 {
	public static void main(String[] args) {
		final int start = 1;
		final int end = 99;
		int index, clapCount;
		
		for (int i = start; i <= end; i++) {
			clapCount = 0;
			index = i;
			
			for (int j = i; j > 0; j /= 10) {
				if ((j % 10 != 0) && (j % 10) % 3 == 0) {
					if (clapCount == 0) {
						System.out.print(i + " 박수 짝");
						clapCount++;
					} else {
						System.out.print("짝");
					}
				}
			}
			if (clapCount != 0) {
				System.out.println();
			}
		}
	}
}
