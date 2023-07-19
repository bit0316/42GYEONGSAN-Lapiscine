/*
 * File name : Homework08_01.java
 * Author : Kim Yeong Ho
 * Date : July 19, 2023
 * Major feature : 
 * - 철수와 컴퓨터의 가위바위보 게임을 만들어보자.
 * - 가위, 바위, 보는 각각 1, 2, 3 키이다.
 * - 철수가 키를 입력하면, 동시에 프로그램도 Math.Random()을 이용하여
 * - 1, 2 3 중에 한 수를 발생시키고 이것을 컴퓨터가 낸 것으로 한다.
 * - 그런 다음 철수와 컴퓨터 중 누가 이겼는지 판별하여 승자를 출력하라.
 * - 철수[가위(1), 바위(2), 보(3), 끝내기(4)] >> 1
 * - 철수(가위) : 컴퓨터(바위)
 * - 컴퓨터가 이겼습니다.
 * - 철수[가위(1), 바위(2), 보(3), 끝내기(4)] >> 3
 * - 철수(보) : 컴퓨터(바위)
 * - 철수가 이겼습니다.
 * - 철수[가위(1), 바위(2), 보(3), 끝내기(4)] >> 4
 */
import java.util.Scanner;

class RockPaperScissors {
	Scanner scanner = new Scanner(System.in);
	String[] choices = { "가위", "바위", "보" };
	int user, computer;
	
	void startGame() {
		while (true) {
			System.out.print("철수[가위(1), 바위(2), 보(3), 끝내기(4)] : ");
			user = scanner.nextInt();

			if (user== 4) break;
			else if (user< 1 || user > 3) {
				System.out.println("잘못된 입력입니다. 다시 입력해주세요.");
				continue;
			}
			
			computer = (int) (Math.random() * 3) + 1;

			System.out.println("철수(" + choices[user - 1]
					+ ") : 컴퓨터(" + choices[computer - 1] + ")");

			if (user == computer) {
				System.out.println("비겼습니다.");
			} else if ((user == 1 && computer == 3)
					|| (user == 2 && computer == 1)
					|| (user == 3 && computer == 2)) {
				System.out.println("철수가 이겼습니다.");
			} else {
				System.out.println("컴퓨터가 이겼습니다.");
			}
		}
		System.out.println("게임을 종료합니다.");
		
		scanner.close();
	}
}

public class Homework08_01 {
	public static void main(String[] args) {
		RockPaperScissors rps = new RockPaperScissors();
		rps.startGame();
	}
}
