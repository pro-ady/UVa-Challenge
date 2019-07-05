#include<bits/stdc++.h>

using namespace std;

int memo_pad[1000];

int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    if(memo_pad[n] != -1){
        return memo_pad[n];
    }
    memo_pad[n] = fib(n-1) + fib(n-2);
    return memo_pad[n];
}

int main(){
    int n;
    cin>>n;

    // Compute the nth Fibonacci Number
    for(int i=0;i<=n;i++){
        memo_pad[i] = -1;
    }

    cout << fib(n);
}
