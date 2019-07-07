// PROBLEM LINK : https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[2001][2001][6];
ll solve(ll *a, ll *b, ll i, ll j, ll n, ll m, ll k){
    if(i==n || j==m)
        return 0;

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    long long int res=0;
    if(a[i] == b[j]){
        res =  1 + solve(a,b,i+1,j+1,n,m,k);
    }

    else{
        if(k>0){
            res = 1 + solve(a,b,i+1,j+1,n,m,k-1);
        }

        res = max(res, solve(a,b,i,j+1,n,m,k));
        res = max(res,solve(a,b,i+1,j,n,m,k));
    }

    return dp[i][j][k] = res;

}


int main(){
    long long int a[2002], b[2002];
    ll n,m,k;
    cin >> n >>m >> k;

    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<m;i++)
        cin>>b[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(a,b,0,0,n,m,k);
}
