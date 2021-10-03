#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number:" << endl;
    int n;
      cin >> n;
      // marking prime number as zero and non-prime as 1.

    int a[n+1] = {0}; // initially assuming all numbers to be prime
    a[0] = 1, a[1] = 1;  

    vector <int> primes;

    for(long long i = 2; i <= n; i++)
    {
        if(a[i] == 0)
        {   
            for(long long j =i * i; j <= n;j += i)  // iterating over all the multiples.
            a[j] = 1;     // marking non-prime number as 1
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0)
        primes.push_back(i);   //pushing all the primes in the primes vector.
    }

    for(int i=0;i<primes.size();i++)
       cout << primes[i] << " ";

}