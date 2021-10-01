package string_arraylist;
import java.util.*;

public class palindromic_strings {
	public static boolean isPalindrome(String str){
		int i = 0, j = str.length() - 1;
		while(i <= j){
			char c1=str.charAt(i);
			char c2=str.charAt(j);
			if(c1!= c2){
				return false;
			}
			else {
			i++;
			j--;
			}
		}
		return true;
	}
	public static void solution(String str) {
		for(int i=1;i<=str.length();i++) {
			for(int j=0;j<i;j++) {
				if(isPalindrome(str.substring(j,i))==true){
					System.out.println(str.substring(j,i));
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		scn.close();
		solution(str);

	}

}
