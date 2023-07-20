/*
 * File name : Won2Dollar.java
 * Author : Kim Yeong Ho
 * Date : July 18, 2023
 * Major feature : 
 * - 다음은 단위를 변환하는 추상 클래스 Converter이다.
 * - Converter 클래스를 상속받아 원화를 달러로 변환하는 Won2Dollar 클래스를 작성하라.
 * - main() 메소드와 실행 결과는 다음과 같다.
 * - 원을(를) 달러(으)로 바꿉니다.
 * - 원을(를) 입력하세요 >> 24000
 * - 변환 결과 : 20.0달러입니다.
 */
package Homework07_01;

import java.util.Scanner;

abstract class Converter {
	abstract protected double convert(double src);
	abstract protected String getSrcString();
	abstract protected String getDestString();
	protected double ratio;
	
	public void run() {
		Scanner scanner = new Scanner (System.in);
		
		System.out.println(getSrcString() + "을(를) " + getDestString() + "(으)로 바꿉니다.");
		System.out.print(getSrcString() + "을(를) 입력하세요 : ");
		double val = scanner.nextDouble();
		double res = convert(val);
		System.out.println("변환 결과 : " + res + getDestString() + "입니다.");
		
		scanner.close();
	}
}

public class Won2Dollar extends Converter {
	protected double convert(double src) { return src / ratio; }
	protected String getSrcString() { return "원"; }
	protected String getDestString() { return "딜러"; }
	public Won2Dollar(double usd) { ratio = usd; }
	
	public static void main(String[] args) {
		Won2Dollar toDollar = new Won2Dollar(1200);
		toDollar.run();
	}
}
