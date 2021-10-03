package string_arraylist;
import java.util.*;
public class string_compress3 {
public static String compress3(String str) {
	String s=str.charAt(0)+"";
	int ctr=1;
	for(int i=1;i<str.length();i++) {
		char cur=str.charAt(i);
		char prv=str.charAt(i-1);
		if(cur==prv) {
			ctr++;
		}
		else {
			if(ctr>1) {
				s+=ctr;
				ctr=1;
			}
			s+=cur;
		}
	}
		
		if(ctr>1) {
			s+=ctr;
			ctr=1;
		}
	
	return s;
}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String str= sc.next();
		sc.close();
		String res=compress3(str);
		int len=res.length();
		System.out.println(len);

	}

}