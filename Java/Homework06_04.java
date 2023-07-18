/*
 * File name : Homework06_04.java
 * Author : Kim Yeong Ho
 * Date : July 18, 2023
 * Major feature : 
 * - 다음은 2차원 상의 한 점을 표현하는 Point 클래스이다.
 * - Point를 상속받아 양수의 공간에서만 점을 나타내는 PositivePoint 클래스를 작성하라.
 * - 다음 main() 메소드를 포함하고 실행 결과와 같이 출력되게 하라.
 * - (10, 10)의 점입니다.
 * - (10, 10)의 점입니다.
 * - (0, 0)의 점입니다.
 */
class Point {
	private int x, y;
	public Point(int x, int y) { this.x = x; this.y = y; }
	public int getX() { return x; }
	public int getY() { return y; }
	protected void move(int x, int y) { this.x = x; this.y = y; }
}

class PositivePoint extends Point {
	public PositivePoint() { super(0, 0); }
	public PositivePoint(int x, int y) { super(0, 0); if (x > 0 && y > 0) super.move(x, y); }
	public void move(int x, int y) { super.move(getX(), getY()); if (x > 0 && y > 0) super.move(x, y); }
	public String toString() { return ("("+ getX() + ", " + getY() + ")의 점"); }
}

public class Homework06_04 {
	public static void main(String[] args) {
		PositivePoint p = new PositivePoint();
		p.move(10, 10);
		System.out.println(p.toString() + "입니다.");
		
		p.move(-5, 5);
		System.out.println(p.toString() + "입니다.");
		
		PositivePoint p2 = new PositivePoint(-10, -10);
		System.out.println(p2.toString() + "입니다.");
	}
}
