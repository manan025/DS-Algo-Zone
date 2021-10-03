package string_arraylist;
import java.util.*;
public class string_compress1 {
	public static String compress(String str) {
		String s=str.charAt(0)+"";
		for(int i=1;i<str.length();i++) {
			char curr=str.charAt(i);
			char prev=str.charAt(i-1);
			if(curr!=prev) {
				s+=curr;
			}
		}
		return s;
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String s=sc.next();
		sc.close();
		String s1=compress(s);
		System.out.println(s1);
	}

}
