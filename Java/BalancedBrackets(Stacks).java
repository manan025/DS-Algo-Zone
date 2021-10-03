import java.util.Scanner;
import java.util.Stack;

public class balancedbrackets {

	    public static void main(String[] args) throws Exception {
	    	
	    	//Accepting string from user
	    	
	        Scanner scn = new Scanner(System.in);
	        String s = scn.nextLine();
	        Stack<Character> st = new Stack<>();
	        
	        //counting open and close brackets
	        //adding only brackets in the stack created
	        
	        int ocount =0;
	        int ccount =0;
	        for(int i=0;i<s.length();i++){
	            char ch = s.charAt(i);
	            if(ch == '(' || ch == '{' || ch == '['){
	                ocount++;
	            }
	            if(ch == ')' || ch == '}' || ch == ']'){
	                ccount++;
	            }
	        }
	        if(ocount != ccount){
	            System.out.println(false);
	            return;
	        }
	        
	        //checking the sequence of open and close brackets
	        
	        for(int i =0;i<s.length();i++){
	            char ch = s.charAt(i);
	            if(ch == '(' || ch == '{' || ch == '['){
	                st.push(ch);
	            }
	            if(ch == ')'){
	                if(st.peek() == '('){
	                    st.pop();
	                }else{
	                    System.out.println(false);      //returning ans
	                    return;
	                }
	            }else if( ch == '}'){
	                if(st.peek() == '{'){
	                    st.pop();
	                }else{
	                    System.out.println(false);		//returning ans
	                    return;
	                }
	            }else if(ch == ']'){
	                if(st.peek() == '['){
	                    st.pop();
	                }else{
	                    System.out.println(false);		//returning ans
	                    return;
	                }
	            }
	        }
	        System.out.println(true);					//returning ans
	    }
	}


/*
---------------------------------------------------------------
JAVA program for 'balanced brackets using stacks' question
Input: An expression in the form of string
Output: returning true/false if brackets match up/don't and balanced/unbalanced
---------------------------------------------------------------
Sample input 1:
[(a + b) + {(c + d) * (e / f)}]
Output:
true
---------------------------------------------------------------
Time Complexity: O(1)
Space Complexity: O(n)
--------------------------------------------------------------- 
 */