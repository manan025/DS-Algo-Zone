#include<bits/stdc++.h>
using namespace std;
void fibonacciSeries(int n){
    int a=0, b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=3; i<=n; i++){
        int c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}
int main(){
    int n;
    cout<<"How long should the series be printed ?  ";
    cin>>n;
    cout<<endl;
    fibonacciSeries(n);
    return 0;
}