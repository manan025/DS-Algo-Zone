using System;
using System.Collections;

namespace DefaultNamespace
{
    public class SieveOfEratosthenes
    {
        private static void Main(string[] args)
        {
            Console.Write("Please enter a random integer number: ");
            if (int.TryParse(Console.ReadLine(), out var num))
            {
                Console.Write($"All primary numbers between 2 and {num} is : ");
                GetAllPrimaryNumbers(num);
            }

            Console.WriteLine();
        }

        /// <summary>
        ///     implementing Sieve_of_Eratosthenes
        /// </summary>
        /// <param name="num">input</param>
        /// <returns>list of primary numbers equals or less than input</returns>
        private static void GetAllPrimaryNumbers(int num)
        {
            if (num <= 1) return;

            var cells = new BitArray(num + 1, true);
            // var cells = new bool[num+1];
            var p = 2;
            while (p <= num)
            {
                // continue if marked false
                if (!cells[p])
                {
                    p++;
                    continue;
                }

                Console.Write(p + ",");

                // mark all multiples of p as false
                for (var i = p; i < num; i++)
                {
                    if (p * i < 2 || p * i > num) break;
                    cells[p * i] = false;
                }

                p++;
            }
        }
    }
}


/*
    // 1
    Please enter a random number: 10
    All primary numbers between 2 and 10 is : 2,3,5,7,
    It took 3957 ms.

    // 2
    Please enter a random number: 200
    All primary numbers between 2 and 200 is : 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,
    83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,
    It took 1425 ms.

*/
