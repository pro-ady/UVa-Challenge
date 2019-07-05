#include<bits/stdc++.h>

using namespace std;

const int inf = (int)1e9;
int memo_pad[10000];
// 1st approach
// Greedy Solution which is incorrect
int no_of_steps(int n){
    if(n==1){
        return 0;
    }

    if(n%3==0){
        return 1 + no_of_steps(n/3);
    }

    if(n%2==0){
        return 1 + no_of_steps(n/2);
    }

    else{
        return 1 + no_of_steps(n-1);
    }
}

// 2nd approach
// Brute Force + Recursion
int no_of_steps_recursive(int n){
    if(n==1){
        return 0;
    }

    int x,y,z;

    if(n%3==0){
        x = 1 + no_of_steps_recursive(n/3);
    }

    if(n%2==0){
        y = 1 + no_of_steps_recursive(n/2);
    }

    z = 1 + no_of_steps_recursive(n-1);

    return min(x,min(y,z));
}

// 3rd approach
// Slightly better recursion
// - incorporates Overlapping Subproblems
int no_of_steps_recursive_2(int n){
    if(n==1)
        return 0;

    if(memo_pad[n] != -1){
        return memo_pad[n] + 1;
    }

    int x,y,z;

    if(n%3==0){
        x = 1 + no_of_steps_recursive(n/3);
    }

    if(n%2==0){
        y = 1 + no_of_steps_recursive(n/2);
    }

    z = 1 + no_of_steps_recursive(n-1);

    memo_pad[n] = min(x,min(y,z));
    return memo_pad[n];
}

// 4th approach
// DP solution
// Bottom Up a.k.a true DP
int no_of_steps_dp(int n){
    int dp[10000];

    // Base Case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int curr = 4; curr<=n;curr++){
        int q1 = INT_MAX,q2=INT_MAX,q3=INT_MAX;

        if(curr%3==0){
            q1 = 1 + dp[curr/3];
        }

        if(curr%2==0){
            q2 = 1 + dp[curr/2];
        }

        q3 = 1 + dp[curr-1];

        dp[curr] = min(q1,min(q2,q3));
    }

    return dp[n];
}


int main(){
    int n;
    cin >> n;

    // 1st
    // cout << no_of_steps(n)

    // 2nd
    // cout << no_of_steps_recursive(n);

    // 3rd
    /*
    for(int i=0;i<=n;i++){
        memo_pad[i] = -1;
    }
    cout << no_of_steps_recursive_2(n);
    */

    // 4th
    cout << no_of_steps_dp(n);

}
