import java.util.Arrays;
import java.util.Scanner;

public class InsertionSort {

    public static void main(String[] args) {
//Efficient for small sized array
//The array is divided into sorted part and unsorted parts
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        for(int i=1;i<n;i++){
int temp = arr[i];
int j =i-1;
//we check if the element is smaller than the sorted part we shift the elements in respective positions
for( j =i-1;j>=0&&arr[j]>temp;j--){
    arr[j+1]=arr[j];
    j--;

}
arr[j+1]=temp;

        }
        System.out.println(Arrays.toString(arr));
    }
}
//Time Complexity
//Best Case: O(n)
//Average and Worst Case: O(n^2)

//Space Complexity
//The Space complexity of thi s program is O(1)