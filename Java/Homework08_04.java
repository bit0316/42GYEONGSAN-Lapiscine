/*
 * File name : Homework08_04.java
 * Author : Kim Yeong Ho
 * Date : July 19, 2023
 * Major feature : 
 * - Vector<Shape>의 벡터를 이용하여 그래픽 편집기를 만들어보자.
 * - 본문 5.6절과 5.7절에서 사례로 든 추상 클래스 Shape과 Line, Rect, Circle 클래스 코드를 잘 완성하고
 * - 이를 활용하여 "삽입", "삭제", "모두 보기", "종료"의 4가지 그래픽 편집 기능 프로그램을 작성하라.
 * - 6장 실습문제 6번을 Vector<Shape>을 이용하여 재작성하는 연습이다.
 * - Vector를 이용하면 6장 실습문제 6번보다 훨씬 간단히 작성됨을 경험할 수 있다.
 * - 그래픽 에디터 beauty를 실행합니다.
 * - 삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> 1
 * - Line(1), Rect(2), Circle(3) >> 2
 * - 삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> 1
 * - Line(1), Rect(2), Circle(3) >> 3
 * - 삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> 3
 * - Rect
 * - Circle
 * - 삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> 2
 * - 삭제할 도형의 위치 >> 3
 * - 삭제할 수 없습니다.
 * - 삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> 4
 * - beauty를 종료합니다.
 */
import java.util.Scanner;
import java.util.Vector;

abstract class Shape {
	abstract void draw();
}

class Line extends Shape {
	void draw() { System.out.println("Line"); }
}

class Rect extends Shape {
	void draw() { System.out.println("Rect"); }
}

class Circle extends Shape {
	void draw() { System.out.println("Circle"); }
}

class GraphicEditor {
	Scanner scanner = new Scanner(System.in);
	Vector<Shape> shapeVector = new Vector<>();

	void startProgram() {
		while(true) {
			System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> ");
			int menu = scanner.nextInt();
			switch (menu) {
			case 1:		insert();								break;
			case 2:		delete();								break;
			case 3:		showAll();								break;
			case 4:		System.out.println("beauty를 종료합니다.");	break;
			default:	System.out.println("잘못된 입력입니다.");		break;
			}
			if (menu == 4) break;
		}
	}
	void insert() {
		System.out.print("Line(1), Rect(2), Circle(3) >> ");
		Shape shape = null;

		int shapeType = scanner.nextInt();
		switch (shapeType) {
		case 1:		shape = new Line();					break;
		case 2:		shape = new Rect();					break;
		case 3:		shape = new Circle();				break;
		default:	System.out.println("잘못된 입력입니다.");	break;
		}
		if (shape != null) shapeVector.add(shape);
	}

	void delete() {
		System.out.print("삭제할 도형의 위치 >> ");

		int input= scanner.nextInt();
		if (input >= 0 && input < shapeVector.size()) shapeVector.remove(input);
		else System.out.println("삭제할 수 없습니다.");
	}

	void showAll() {
		for (Shape s : shapeVector) {
			s.draw();
		}
	}
}

public class Homework08_04 {
	public static void main(String[] args) {
		GraphicEditor ge = new GraphicEditor();
		ge.startProgram();
	}
}
