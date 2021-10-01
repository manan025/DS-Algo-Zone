/* PROBLEM STATEMENT : WRITE A JAVA PROGRAM TO IMPLEMENT BUBBLE SORT USING TWO STACKS */


/* 
Sample Input: 
             n = 5
             arr[ ] = {12, 4, 3, 67, 1}
             
Sample Output: 1 3 4 12 67
  */

import java.util.*;  
class Sort{ 
    
    static void bubbleSortStack(int a[], int n){ 
        Stack<Integer> s1 = new Stack<>(); 
          
        for(int num : a){ 
            s1.push(num);
        }
          
        Stack<Integer> s2 = new Stack<>(); 
          
        for(int i = 0; i < n; i++){ 
            
            if(i % 2 == 0){ 
                while (!s1.isEmpty()){ 
                    int t = s1.pop(); 
                      
                    if(s2.isEmpty()){ 
                        s2.push(t);  
                    }
                    
                    else{ 
                        
                        if(s2.peek() > t){ 
                            int temp = s2.pop(); 
                            s2.push(t); 
                            s2.push(temp); 
                        } 
                        
                        else{ 
                            s2.push(t); 
                        } 
                    } 
                } 
                a[n-1-i] = s2.pop(); 
            }     
            
            else{
                
                while(!s2.isEmpty()){ 
                    int t = s2.pop(); 
                      
                    if (s1.isEmpty()){ 
                        s1.push(t); 
                    }
                      
                    else{ 
                        
                        if (s1.peek() > t){ 
                            int temp = s1.pop(); 
                              
                            s1.push(t); 
                            s1.push(temp); 
                        } 
                        
                        else{
                            s1.push(t); 
                        }
                    } 
                } 
                  
                a[n-1-i] = s1.pop(); 
            } 
        }
        
        for(int i = 0; i < n; i++){
            System.out.print(a[i]+" "); 
        }
    } 
      
    public static void main(String[] args){
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int a[] = new int[n];
        for(int i = 0;i<n;i++){
          a[i] = scan.nextInt();
        }
        bubbleSortStack(a, n); 
    } 
}

/* Complexity Analysis
  (i) Time Complexity : O(n^2) where n is the number of integers in given array a[ ]. This is the usual time complexity required by Bubble Sort.
  (ii) Space Complexity : O(n) because we used space for n elements. This storage is required for stacks.
*/
