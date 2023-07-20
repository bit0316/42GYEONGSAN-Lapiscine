/*
 * File name : Homework04_02.java
 * Author : Kim Yeong Ho
 * Date : July 13, 2023
 * Major feature : 
 * - 다음 그림과 같은 구조를 가지는  double 타입의 2차원 배열을 선언하고,
 * - 값을 직접 배열에 삽입하는 방법으로 그림에 있는 값으로 초기화하고, 출력하는 코드를 작성하시오.
 * - 1.1  1.2  1.3  1.4
 * - 2.1  2.2
 * - 3.1  3.2  3.3
 * - 4.1
 */
package Homework04_02;

public class Homework04_02 {
	public static void main(String[] args) {
		final int row = 4;
		final int[] col = {4, 2, 3, 1};
		
		double arr[][] = new double[row][];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = new double[col[i]];
			for (int j = 0; j <arr[i].length; j++) {
				arr[i][j] = (i + 1) + (j + 1) * 0.1;
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
