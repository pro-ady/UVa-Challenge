// Given an NxN grid, calculate the minimum cost in traveling from the starting to ending cell
// We have been provided with the weights of traveling through the various cells

#include<bits/stdc++.h>

using namespace std;

int mini_travel_cost_dp(int a[][100], int r,int c){
    int dp[100][100] = {};

    dp[0][0] = a[0][0];

    // Filling the first row and filling first column
    for(int j=1;j<c;j++){
        dp[0][j] = a[0][j] + dp[0][j-1];
    }

    for(int i=1;i<r;i++){
        dp[i][0] = a[i][0] + dp[i-1][0];
    }

    // Filling the other cells
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
            dp[i][j] += a[i][j];
        }
    }

    return dp[r-1][c-1];
}

int main(){
    int a[][100] = {{1,2,3},
                    {4,8,2},
                    {1,5,3}};

    int n = 3;

    cout << mini_travel_cost_dp(a,3,3);
}
