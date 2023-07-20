/*
 * File name : Homework06_03.java
 * Author : Kim Yeong Ho
 * Date : July 17, 2023
 * Major feature : 
 * - 다음은 2차원 상의 한 점을 표현하는 Point 클래스이다.
 * - Point를 상속받아 색을 가진 점을 나타내는 ColorPoint 클래스를 작성하라.
 * - 다음 main() 메소드를 포함하고 실행 결과와 같이 출력되게 하라.
 * - BLACK색의 (0,0)의 점입니다.
 * - RED색의 (5,5)의 점입니다.
 */
package Homework06_03;

class Point {
	private int x, y;
	public Point(int x, int y) { this.x = x; this.y = y; }
	public int getX() { return x; }
	public int getY() { return y; }
	protected void move(int x, int y) { this.x = x; this.y = y; }
}

class ColorPoint extends Point {
	private String color;
	public ColorPoint() { super(0, 0); this.color = "BLACK"; }
	public ColorPoint(int x, int y) { super(x, y); this.color = "BLACK"; }
	public ColorPoint(int x, int y, String color) { super(x, y); this.color = color; }
	public void setXY(int x, int y) { this.move(x, y); }
	public void setColor(String color) { this.color = color; }
	public String toString() { return (this.color + "색의 ("+ getX() + ", " + getY() + ")의 점"); }
}

public class Homework06_03 {
	public static void main(String[] args) {
		ColorPoint zeroPoint = new ColorPoint();
		System.out.println(zeroPoint.toString() + "입니다.");
		
		ColorPoint cp = new ColorPoint(10, 10);
		cp.setXY(5, 5);
		cp.setColor("RED");
		System.out.println(cp.toString() + "입니다.");
	}
}
