/*
 * File name : Homework05_01.java
 * Author : Kim Yeong Ho
 * Date : July 14, 2023
 * Major feature : 
 * - Grade 클래스를 작성해보자.
 * - Grade 클래스에 int 타입의 math, science, english 필드를 private로 선언하고,
 * - 생성자와 세 과목의 평균을 리턴하는 average() 메소드를 작성한다.
 * - 수학, 과학, 영어 순으로 3개의 점수 입력>>90 88 96
 * - 평균은 91
 */
package Homework05_01;

import java.util.Scanner;

class Grade {
	private int math, science, english;
	private float avg;
	
	public Grade(int math, int science, int english) {
		this.math = math;
		this.science = science;
		this.english = english;
	}
	
	public float average() {
		avg = (float)(this.math + this.science + this.english) / 3;
		return avg;
	}
}

public class Homework05_01 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("수학, 과학, 영어 순으로 3개의 점수 입력 : ");
		int math = scanner.nextInt();
		int science = scanner.nextInt();
		int english = scanner.nextInt();
		
		Grade me = new Grade(math, science, english);
		System.out.println("평균은 " + me.average());
		
		scanner.close();
	}
}
