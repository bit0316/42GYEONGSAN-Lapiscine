/*
 * File name : Homework08_03.java
 * Author : Kim Yeong Ho
 * Date : July 19, 2023
 * Major feature : 
 * - 도시 이름, 위도, 경도 정도를 가진 Location 클래스를 작성하고,
 * - 도시 이름을 '키'로 하는 HashMap<String, Location> 컬렉션을 만들고,
 * - 사용자로부터 입력 받아 4개의 도시를 저장하라.
 * - 그리고 도시 이름으로 검색하는 프로그램을 작성하라.
 * - 도시, 경도, 위도를 입력하세요.
 * - >> 서울, 37, 126
 * - >> LA, 34, -118
 * - >> 파리, 2, 48
 * - >> 시드니, 141, -33
 * - --------------------
 * - 서울   37    126
 * - LA    34   -118
 * - 파리   2     48
 * - 시드니  151  -33
 * - --------------------
 * - 도시 이름 >> 피리
 * - 피리는 없습니다.
 * - 도시 이름 >> 파리
 * - 파리  2  48
 * - 도시 이름 >> 그만
 */
import java.util.Scanner;
import java.util.HashMap;

class Location {
	public String cityName;
	public String longitude;
	public String latitude;

	public Location(String cityName, String longitude, String latitude) {
		this.cityName = cityName;
		this.longitude = longitude;
		this.latitude = latitude;
	}
}

class CitySearch {
	Scanner scanner = new Scanner(System.in);
	private final int size = 4;
	private HashMap<String, Location> cityMap = new HashMap<>();
	private String cityName, latitude, longitude;

	void startProgram() {
		inputCities(size);
		printCities(cityMap);
		searchCity(cityMap);
		
		scanner.close();
	}
	
	void inputCities(int size) {
		System.out.println("도시, 경도, 위도를 입력하세요.");
		for (int i = 0; i < size; i++) {
			System.out.print(">> ");
			String input = scanner.nextLine();
			String[] parts = input.split(",");
			if (parts.length != 3) {
				System.out.println("잘못된 입력 형식입니다. 도시 이름, 위도, 경도를 입력하세요.");
				i--;
				continue;
			}

			cityName = parts[0];
			latitude = parts[1];
			longitude = parts[2];

			cityMap.put(cityName, new Location(cityName, latitude, longitude));
		}
	}
	
	void printCities(HashMap<String, Location> cityMap) {
		System.out.println("--------------------");
		for (Location location : cityMap.values()) {
			printCity(location);
		}
		System.out.println("--------------------");

	}
	
	void printCity(Location location) {
		System.out.println(location.cityName
				+ "\t" + location.longitude
				+ "\t" + location.latitude);
	}
	
	void searchCity(HashMap<String, Location> cityMap) {
		while (true) {
			System.out.print("도시 이름 >> ");
			String input = scanner.nextLine();
			if (input.equals("그만")) { break; }

			Location location = cityMap.get(input);
			if (location != null) {
				printCity(location);
			} else {
				System.out.println(input + "는 없습니다.");
			}
		}
		System.out.println("프로그램을 종료합니다.");
	}
}

public class Homework08_03 {
	public static void main(String[] args) {
		CitySearch cs = new CitySearch();
		cs.startProgram();
	}
}
