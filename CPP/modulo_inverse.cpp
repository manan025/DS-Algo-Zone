#include <bits/stdc++.h>
using namespace std;
#define ll long long
 


void power( ll n, ll m, ll mod)
{
    ll res=1,num=n;

    while(m)
    {
        if(m%2)
        {
            res=((res%mod) * (n%mod))%mod;
            m-=1;
        }

        else
        {
            n=((n%mod) * (n%mod))%mod;
            m/=2;
        }
    }

    cout<<"modulo inverse of number "<<num<<" under modulo "<<mod<<" is: ";
    cout<<res;
}

 
int main()
{
    cout << "Number: ";

    ll num;
    cin >> num;

    cout << "Modulo: ";

    ll mod;
    cin >> mod;

    /*
    calculate modulo inverse using Fermet's little theorm
    
    condition:
        modulo inverse of number (num) under modulo (mod) exiest iff Gcd(num,mod)=1
    
    according to Fermet's theorm-
        (num)^(mod-1) ≅ 1
        (num)^(mod-2) ≅ (num)^(-1)

    */

    power(num, mod-2, mod);

    //power function calculate num power mod-2 under modulo (mod) using binary exponentiation (which allows to calculate an using only O(logn) multiplications)

    return 0;
}


/*

sample Test case:

Number: 10
Modulo: 7
modulo inverse of number 10 under modulo 7 is: 5

*/