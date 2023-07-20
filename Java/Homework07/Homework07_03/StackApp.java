/*
 * File name : StackApp.java
 * Author : Kim Yeong Ho
 * Date : July 18, 2023
 * Major feature : 
 * - 다음 Stack 인터페이스를 상속받아 실수를 저장하는 StringStack 클래스를 구현하라.
 * - 그리고 다음 실행 사례와 같이 작동하도록 StackApp 클래스에 main() 메소드를 작성하라.
 * - 총 스택 저장 공간의 크기 입력 >> 3
 * - 문자열 입력 >> hello
 * - 문자열 입력 >> sunny
 * - 문자열 입력 >> smile
 * - 문자열 입력 >> happy
 * - 스택이 꽉 차서 푸시 불가!
 * - 문자열 입력 >> 그만
 * - 스택에 저장된 모든 문자열 팝 : smile sunny hello
 */
package Homework07_03;

import java.util.Scanner;

interface Stack {
	int capacity();
	int length();
	String pop();
	boolean push(String val);
}

class StringStack implements Stack {
	private int size;
	private int top;
	private String[] stackArr;

	public int capacity() { return size; }
	
	public int length() { return top + 1; }
	
	public String pop() {
		if (size == 0) return null;
		String value = stackArr[top - 1];
		stackArr[top - 1] = null;
		top--;
		return value;
	}
	
	public boolean push(String val) {
		if (top >= size) return false;
		stackArr[top] = val;
		top++;
		return true;
	}

	public StringStack(int stackSize) {
		this.size= stackSize;
		this.stackArr = new String[stackSize];
		this.top = 0;
	}
}

public class StackApp {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("총 스택 저장 공간의 크기 입력 : ");
		int stackSize = scanner.nextInt();
		StringStack stack = new StringStack(stackSize);

		while (true) {
			System.out.print("문자열 입력 >> ");
			String input = scanner.next();
			if (input.equals("그만")) break;
			if (!stack.push(input)) System.out.println("스택이 꽉 차서 푸시 불가!");
		}
		
		System.out.print("스택에 저장된 모든 문자열 팝: ");
		for (int i = 0; i <= stack.length(); i++) {
			System.out.print(stack.pop() + " ");
		}

		scanner.close();		
	}
}
