/*
 * File name : Homework08_02.java
 * Author : Kim Yeong Ho
 * Date : July 19, 2023
 * Major feature : 
 * - Vector 컬렉션을 이용하여 강수량의 평균을 유지 관리하는 프로그램을 작성하라.
 * - 강수량을 입력하면 벡터에 추가하고 현재 입력된 모든 강수량과 평균을 출력한다.
 * - 강수량 입력 (0 입력시 종료) >> 5
 * - 5
 * - 현재 평균 5
 * - 강수량 입력 (0 입력시 종료) >> 80
 * - 5 80
 * - 현재 평균 42
 * - 강수량 입력 (0 입력시 종료) >> 53
 * - 5 80 53
 * - 현재 평균 46
 * - 강수량 입력 (0 입력시 종료) >> 22
 * - 5 80 53 22
 * - 현재 평균 40
 * - 강수량 입력 (0 입력시 종료) >> 0
 */
import java.util.Scanner;
import java.util.Vector;

class RainfallAverage {
	Scanner scanner = new Scanner(System.in);
	Vector<Double> rainfallList = new Vector<>();
	double sum = 0, average = 0;
	
	void startProgram() {
		while (true) {
			System.out.print("강수량 입력 (0 입력시 종료) : ");
			double rainfall = scanner.nextDouble();

			if (rainfall == 0) break;
			else if (rainfall < 0) {
				System.out.println("잘못된 입력입니다. 다시 입력해주세요.");
				continue;
			}

			rainfallList.add(rainfall);
			sum += rainfall;
			average = sum / rainfallList.size();

			System.out.print("현재 입력된 강수량: ");
			for (double value : rainfallList) {
				System.out.print(value + " ");
			}
			System.out.println();
			System.out.println("현재 평균: " + average);
		}
		System.out.println("프로그램을 종료합니다.");

		scanner.close();
	}
}

public class Homework08_02 {
	public static void main(String[] args) {
		RainfallAverage ra = new RainfallAverage();
		ra.startProgram();
	}
}
