/*
 * C#  Program to Generate Fibonacci Series
 */
using System;
namespace Program
{
    public class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Please enter the Length of the Fibonacci Series: ");
            int number = int.Parse(Console.ReadLine());
            FibonacciSeries(0, 1, 1, number);
            Console.ReadKey();
        }
        public static void FibonacciSeries(int firstNumber, int secondNumber, int counter, int number)
        {
            Console.Write(firstNumber + " ");
            if (counter < number)
            {
                FibonacciSeries(secondNumber, firstNumber + secondNumber, counter + 1, number);
            }
        }
    }

}

/*Please enter the Length of the Fibonacci Series: 10
0 1 1 2 3 5 8 13 21 34

Time Complexity: O(n)
Space Complexity: O(1)*/