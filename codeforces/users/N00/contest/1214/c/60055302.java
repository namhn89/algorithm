import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt() ;
		String str = sc.next() ;
		int bla = 0 ;
		int minbla = n ;
		for (int index = 0; index < str.length(); ++index){
			if (str.charAt(index) == '(') bla += 1;
			else bla -= 1 ;
			minbla = Math.min(bla, minbla);
		}
//		System.out.println("bla = " + bla);
//		System.out.println("minbla = " + minbla);
		if (bla != 0){
			System.out.println("No");
		}
		else {
			if (minbla >= -1) {
				System.out.println("Yes");
			} else System.out.println("No");
		}
	}
}