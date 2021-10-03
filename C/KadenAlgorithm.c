#include<stdio.h>
#include<stdbool.h>


int maxValue(int a, int b) {
    if(a > b) return a;
    return b;
}

/*
*   Finding max subarray sum using Kaden's/Kadane's algorithm.
*   If all the values in the array are lower than zero then we can simply return the value which is closer to zero.
*   otherwise we can try to find subarray with maximum with the following steps:
*   1) Initialize a global variable sum equals to zero. NOTE: this approach will only work if there is at least non-negative element, otherwise we need to handle the as stated above.
*   2) Initialize another temp variable say, 'temp' equals to zero.
*   3) Start iterating the array and adding the array value at ith index to variable temp.
*   4) If at any point, the temp variable is greater than sum variable then update sum. or if the temp variable is lower than zero then reset temp variable to zero.
*   5) After iterating the whole array, check if there is at least one non-negative element or not, if there is then simply return the sum value otherwise return the negative value closer to the zero.
*/
int maxSubarraySum(int* arr, int size) {
    bool allNegative = true;
    int maxValueInArray = arr[0];
    int maxSum = 0;
    int tempSum = 0;

    for(int i = 0; i < size; i++) {
        tempSum += arr[i];
        if(arr[i] >= 0) {
            allNegative = false;
        }
        maxValueInArray = maxValue(maxValueInArray, arr[i]);
        maxSum = maxValue(maxSum, tempSum);
        tempSum = maxValue(tempSum, 0);
    }

    if(allNegative) return maxValueInArray;
    return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) {
        printf("array size must be greater than 0\");
        return -1;
    }

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxSum = maxSubarraySum(arr, n);
    printf("%d\n", maxSum);
    return 0;
}

/*
* Input sample
* 5
* 3 -2 -2 5 -1
* Expected output
* 5
*/


