using System; 
namespace remove_even_int_fromarray
{
    class Solution
    {
        static int [] removeEven(int[]Arr, int size)
        {
            int m = 0;
            for (int i = 0; i < size; i++)
            {
                if (Arr[i] % 2 != 0)  // if odd number found
                {
                    Arr[m] = Arr[i];   //inserting odd values in the array
                    ++m;
                }
            }
            int[] temp = new int[m];
            for (int i = 0; i < m; i++)
                temp[i] = Arr[i];
         
            Arr = temp;
            return Arr;  // returning the array after removing the odd numbers
        }
        //Remove Event Integers from an Array:
        static void Main(string[] args)
        {
            int[] arr = null;      // declaring array
            arr = new int[10];   // memory allocation
            Console.Write("Before remove even: ");
            for (int i = 0; i < 10; i++)
            {
                arr[i] = i;      // assigning values
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine("");
            arr = removeEven(arr, 10);   // calling removeEven
            Console.Write("After remove even: ");
            for (int i = 0; i < 5; i++)
            {
                Console.Write( arr[i] + " ");    // prinitng array
            }
            Console.WriteLine(""); 
            return ;
        }

    }
}

/*Sample Output:
Before remove even: 0 1 2 3 4 5 6 7 8 9 
After remove even: 1 3 5 7 9 */ 