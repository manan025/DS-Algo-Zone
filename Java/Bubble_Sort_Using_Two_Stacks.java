import java.util.*;
public class Bubble_Sort_Using_Two_Stacks{
  //driver method
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int arr[] = new int[n];
    for(int i = 0;i<n;i++){
      arr[i] = sc.nextInt();
    }
    bubblesortstack(n,arr);
  }
  //Method for Bubble Sort by using Stack Data Structure
  static void bubblesortstack(int n, int arr[]){
    //Stack-1
    Stack <Integer> S = new Stack<>();
    for(int number:arr){
      S.push(number);
    }
    //Stack-2
    Stack <Integer> S1 = new Stack<>();
    for(int i = 0;i<n;i++){
      if(i%2==0){
        while(!S.isEmpty()){
          int I = S.pop();
          if(S1.isEmpty()){
            S1.push(I);
          }
          else{
            if(S1.peek()>I){
              int temp = S1.pop();
              S1.push(I);
              S1.push(temp);
            }
            else{
              S1.push(I);
            }
          }
        }
        arr[n-1-i] = S1.pop();
      }
      else{
        while(!S1.isEmpty()){
            int I = S1.pop();
            if (S.isEmpty()){
                S.push(I);
            }
            else
            {
              if (S.peek() > I)
              {
                int temp = S.pop();
                S.push(I);
                S.push(temp);
              }
              else{
                S.push(I);
              }
          }
        }
      arr[n-1-i] = S.pop();
      }
    }
    System.out.println(Arrays.toString(arr));
  }
}
