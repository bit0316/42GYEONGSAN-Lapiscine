/*
 * File name : Homework04_03.java
 * Author : Kim Yeong Ho
 * Date : July 13, 2023
 * Major feature : 
 * - 4 x 4의 정수형 2차원 배열을 만들고, 이 배열에 1에서 10까지 범위의 정수를 16개 램덤하게 생성하여 저장한 후에,아래와 같이 2차원 배열을 출력하는 프로그램을 작성하시오. 
 * - 6 10  1  8
 * - 1  3  7  2
 * - 8  4  5  1
 * - 1  8  4  4
 * - 참고로 1에서 10까지 범위의 점수를 램덤하게 생성할 때는 다음 코드를 이용하라.
 * - import java.lang.Math;
 * - int i = (int)(Math.random() * 10 + 1);
 */
import java.lang.Math;

public class Homework04_03 {
	public static void main(String[] args) {
		final int row = 4, col = 4;
		
		int[][] arr = new int[row][col];
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				arr[i][j] = (int)(Math.random() * 10 + 1);
			}
		}
		
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j <arr[i].length; j++) {
				System.out.print(arr[i][j] + "\t");
			}
			System.out.println();
		}
	}
}
