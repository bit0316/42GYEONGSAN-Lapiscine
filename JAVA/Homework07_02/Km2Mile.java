/*
 * File name : Km2Mile.java
 * Author : Kim Yeong Ho
 * Date : July 18, 2023
 * Major feature : 
 * - 다음은 단위를 변환하는 추상 클래스 Converter이다.
 * - Converter 클래스를 상속받아 km를 mile로 변환하는 Km2Mile 클래스를 작성하라.
 * - main() 메소드와 실행 결과는 다음과 같다.
 * - km을(를) mile(으)로 바꿉니다.
 * - km을(를) 입력하세요 >> 30
 * - 변환 결과 : 18.75mile입니다.
 */
package Homework07_02;

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

public class Km2Mile extends Converter {
	protected double convert(double src) { return src / ratio; }
	protected String getSrcString() { return "km"; }
	protected String getDestString() { return "mile"; }
	public Km2Mile(double mile) { ratio = mile; }
	
	public static void main(String[] args) {
		Km2Mile toMile = new Km2Mile(1.6);
		toMile.run();
	}
}
