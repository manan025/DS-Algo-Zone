

/* 	Sieve of eratosthenes is the algorithm to 
	find all the prime numbers less than or 
	equal to a given integer n using c language.


	Solution:-
		We will first take a array of size 1e6, and assign 
		each value to 1(except 0 and 1), assuming they are 
		prime numbers, now we will start a loop starting 
		from 2 till square root of 1e6, and check if value 
		of that i indexed in array is 1 or not, if found 1
		we will now iterate (in var j) from i*i (as all 
		other values are covered till now) till the value 
		is less than 1e6, in each operation we will change
		the value of array at index j equals to 0,then 
		increment it to j+=i;
*/


#include<stdio.h>
using namespace std;


// Function of seive_of_eratosthenes to find all primes till (1e6).

int seive_of_eratosthenes(int a[1000000]){
	int num = (1e6); //size of array

	for(int i=0; i<num; i++) {
		a[i] = 1;		// initilize each to 1.
	}
	a[0] = 0;
	a[1] = 0;

	for(int i=2 ; i*i<num ; i++) {
		if(a[i] == 1) {
			for(int j = i*i ; j<num; j+=i) {
				a[j] = 0;
			}
		}
	}
	return *a;
}

int main() {

	int arr[1000000];

	seive_of_eratosthenes(arr);

	int num;
		// taking input
	printf("Enter a number less than 1000000 and greater than 0 \n");

	scanf("%d", &num);

		// print prime numbers less than or equal to num  
	if(num<1000000 && num>0) {
		for(int i=0; i<=num; i++) {
			if(arr[i] == 1)
			 printf("%d ", i);
		}
	}
	else
		printf("%s","Enter a valid number");
}


/* 	Case 1:- Input:
	Enter a number less than 1000000 and greater than 0 
	13

	Output:
	2 3 5 7 11 13 


	Case 2:- Input:
	Enter a number less than 1000000 and greater than 0 
	13

	Output:
	2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79


	Case 3:- Input:
	Enter a number less than 1000000 and greater than 0 
	-1

	Output:
	Enter a valid number

	Space Complexity:- O(sqroot(n))
	Time Complexity:- O(n * log( log(n))) 
 
*/
