// Given a rod of some length, calculate the maximum cost you can get by cutting the rod
// The price at which certain lengths of rod is sold is given

#include<bits/stdc++.h>

using namespace std;

// 1st Approach
// Recursive
int max_cost_recursive(int rod_len, int len_price[], int n){
    if(rod_len<=0)
        return 0;

    int cost=0;
    int maxi_cost = 0;

    maxi_cost = INT_MIN;

    for(int cut=1;cut<=rod_len;cut++){
        cost = len_price[cut] + max_cost_recursive(rod_len-cut, len_price, n);

        if(cost > maxi_cost)
            maxi_cost = cost;
    }

    return maxi_cost;
}

// 2nd approach
// Memoization
int memo[100] = {INT_MAX};
int max_cost_memo(int rod_len, int len_price[]){
    if(rod_len==0){
        return 0;
    }

    if(memo[rod_len] != -1){
        return memo[rod_len];
    }

    memo[rod_len] = len_price[rod_len];
    int cost,maxi_cost=0;
    for(int cut=1;cut<=rod_len;cut++){
        cost = len_price[cut] + max_cost_memo(rod_len-cut, len_price);

        if(cost > maxi_cost)
            maxi_cost = cost;
    }

    memo[rod_len] = max(memo[rod_len], maxi_cost);

    return memo[rod_len];
}

// 3rd approach
// Bottom Up

int max_cost_bottom_up(int rod_len, int len_price[]){
    int dp[1000] = {};

    for(int len=1; len<=rod_len; len++){
        int maxi = 0;
        for(int cut=1;cut<=len;cut++){
            maxi = max(maxi,len_price[cut] + dp[len - cut]);
        }
        dp[len] = maxi;
    }

    return dp[rod_len];
}

int main(){
    int rod_len = 4;

    int len_price[] = {INT_MIN, 2,3,2,5};
    int n = sizeof(len_price)/sizeof(len_price[0]);

    // 1st
    cout << max_cost_recursive(rod_len, len_price, n);

    // 2nd
    for(int i=1;i<=rod_len;i++){
        memo[i] = -1;
    }

    cout << "\n" << max_cost_memo(rod_len, len_price);

    // 3rd
    cout << "\n" << max_cost_bottom_up(rod_len,len_price);

}
