// You have some wine bottles whose prices increase with the year linearly, i.e. Price of Wine = Original Price * No. of years
// These bottles are arranged in a given order
// We have to sell the bottles AT EITHER ENDS of this line, in such a way that we have the maximum profit
#include<bits/stdc++.h>

using namespace std;

// 1st Approach
// Works but is it efficient?

// Checking the number of times this function ran
int maximum_profits_recursion(int a[], int start, int end, int year){
    if(start==end){
        return a[start]*year;
    }

    if(start > end){
        return 0;
    }

    int q1 = a[start]*year + maximum_profits_recursion(a,start+1,end,year+1);
    int q2 = a[end]*year + maximum_profits_recursion(a,start,end-1,year+1);

    return max(q1,q2);
}

// 2nd approach
// Memoization

int memo[100][100];
int maximum_profits_memo(int a[], int start, int end, int year=1){
    if(start>end){
        return 0;
    }

    if(memo[start][end] != -1){
        return memo[start][end];
    }

    if(start==end){
        memo[start][end] = a[start]*year;
        return memo[start][end];
    }

    int q1 = a[start]*year + maximum_profits_memo(a,start+1,end,year+1);
    int q2 = a[end]*year + maximum_profits_memo(a,start,end-1,year+1);

    memo[start][end] = max(q1,q2);

    return memo[start][end];
}

// 3rd Approach
// Filling Up Table using Bottom Up
int maximum_profits_bottom_up(int a[], int n){
    int dp[100][100] = {};
    int year = n;

    for(int i=0;i<n;i++){
        dp[i][i] = a[i] * year; // Selling single bottles in the last year
    }

    // len = n - year
    for(int len=2; len<=n; len++){
        year--;
        int start = 0;
        int end = n - len;

        while(start <= end){
            int endOfWindow = start + len -1;
            dp[start][endOfWindow] = max(a[start]*year + dp[start+1][endOfWindow],
                                         a[endOfWindow]*year + dp[start][endOfWindow-1]);
            start++;
        }
    }
    cout << endl << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << setw(3) << dp[i][j] << " , ";
        }
        cout << endl;
    }

    return dp[0][n-1];
}

int main(){
    int a[] = {2,3,5,1,4};
    int n = sizeof(a)/sizeof(a[0]);

    // 1st approach
    cout << maximum_profits_recursion(a,0,n-1,1);

    //2nd approach
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            memo[i][j] = -1;
        }
    }
    cout << endl;
    cout << maximum_profits_memo(a,0,n-1,1);

    cout << endl << endl << maximum_profits_bottom_up(a,n);
}
