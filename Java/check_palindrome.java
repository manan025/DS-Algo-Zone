package string_arraylist;

import java.util.Scanner;

public class check_palindrome {
	public static boolean ispal(String s) {
		int i=0;
		int j=s.length()-1;
		while(i<j) {
			char c1=s.charAt(i);
			char c2=s.charAt(j);
			if(c1!=c2) {
				return false;
			}
			i++;
			j--;
		}
		return true;
		
		
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String s =sc.next();
		boolean b=ispal(s);
		if(b==true) {
			System.out.println("the string is palindrome");
		}
		else {
			System.out.println("the given string is not palindrome");
		}
		

	}

}
