#include<bits/stdc++.h>

using namespace std;

int fib(int n){
    int dp[1000] = {};

    dp[0] = 0;
    dp[1] = 1;

    for(int curr=2;curr<=n; curr++){
        dp[curr] = dp[curr-1] + dp[curr-2];
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    cout << fib(n);
}
