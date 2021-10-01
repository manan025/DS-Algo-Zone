package string_arraylist;

public class string_intro {

	public static void main(String[] args) {
//		string declaration and assignment
		String s="hello world";
		System.out.println(s);
//		substrings
		String x;
		x="abcd";
		for(int i=1;i<=x.length();i++) {
			for(int j=0;j<i;j++) {
				System.out.print(x.substring(j,i)+" ");
			}
			System.out.println();
		}
//		adding two strings or adding content in a string 
		String s1="hello";
		String s2="Jaskirat";
		s1+=" I am ";
		String s3=s1+s2;
		System.out.println(s3);
		System.out.println(s3+" "+10+20);
		System.out.println(10+20+" "+s3);
//		we cannot edit out characters in a string
//		split constant in string
		String h="abc def ghi jkl mno";
		String[] part=h.split(" ");
		for(int i=0;i<part.length;i++) {
			System.out.println(part[i]);
		}

	}

}
