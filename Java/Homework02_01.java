/*
 * File name : Homework02_01.java
 * Author : Kim Yeong Ho
 * Date : July 11, 2023
 * Major feature : 
 * - 2차원 평면에서 직사각형은 왼쪽 상단 모서리와 오른쪽 하단 모서리의 두 점으로 표현한다.
 * - (100, 100)와 (200, 200)의 두 점으로 이루어진 사각형이 있을 때,
 * - Scanner를 이용하여 정수 x와  y의 값을 입력받고 점 (x,y)가 이 직사각형 안에 있는 지를 판병하는 프로그램을 작성하시오.
 * - 점 (x, y)의 좌표를 입력하시오>>150, 150 
 * - (150, 150) 는 사각형 안에 있습니다. 
 */
import java.util.Scanner;

public class Homework02_01 {
	public static void main(String[] args) {
		final int[][] rectangle = {{100, 100}, {200, 200}};
		int positionX, positionY;
		String result;
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("점 (x, y)의 좌표를 입력하시오 : ");
		positionX = scanner.nextInt();
		positionY = scanner.nextInt();

		result = (rectangle[0][0] <= positionX && positionX <= rectangle[1][0]) &&
				 (rectangle[0][1] <= positionY && positionY <= rectangle[1][1]) ? "있습니다." : "없습니다.";
		System.out.println("점 (" + positionX + ", " + positionY + ")은(는) 사각형 안에 " + result);

		scanner.close();
	}
}
