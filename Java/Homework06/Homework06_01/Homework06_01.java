/*
 * File name : Homework06_01.java
 * Author : Kim Yeong Ho
 * Date : July 17, 2023
 * Major feature : 
 * - 다음과 같은 Dictionary 클래스가 있다.
 * - 실행 결과가 같이 작동하도록 Dictionary 클래스의 kor2Eng() 메소드와 DicApp 클래스를 작성하라.
 * - 한영단어 검색 프로그램입니다.
 * - 한글 단어? 희망
 * - 희망은 hope
 * - 한글 단어? 아가
 * - 아가는 저의 사전에 없습니다.
 * - 한글 단어? 아기
 * - 아기는 baby
 * - 한글 단어? 그만 -> "그만"을 입력하면 프로그램 종료
 */
package Homework06_01;

import java.util.Scanner;

class Dictionary {
	private static String[] kor = {"사랑", "아기", "돈", "미래", "희망"};
	private static String[] eng = {"love", "baby", "money", "future", "hope"};
	
	public static String kor2Eng(String word) {
		String result = "";
		for (int i = 0; i < kor.length; i++) {
			if (word.equals(kor[i])) {
				result = eng[i];
				break;
			}
		}
		return result;
	}
}

public class Homework06_01 {
	public static void main(String[] args) {
		String kor = "", eng = null;
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("한영 단어 검색 프로그램입니다.");
		while (true) {
			System.out.print("한글 단어 : ");
			kor = scanner.nextLine();
			if (kor.equals("그만")) break;
			
			eng = Dictionary.kor2Eng(kor);
			String result = !(eng.equals("")) ? (kor + "은(는) " + eng) : (kor + "은(는) 저의 사전에 없습니다.");
			System.out.println(result);
		}
		
		scanner.close();
	}
}
