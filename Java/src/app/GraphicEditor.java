/*
 * File name : GraphicEditor.java
 * Author : Kim Yeong Ho
 * Date : July 18, 2023
 * Major feature : 
 * - 다음 코드를 수정하여 Shape 클래스는 base 패키지에,
 * - Circle 클래스는 derived 패키지에,
 * - GraphicEditor 클래스는 app 패키지에 분리 작성하라.
 */
package app;
import base.Shape;
import derived.Circle;

public class GraphicEditor {
	public static void main(String[] args) {
		Shape shape = new Circle();
		shape.draw();
	}
}
