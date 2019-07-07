#include<bits/stdc++.h>

using namespace std;

int lcs_recursive(string a, string b, int i, int j){
    if(i >= a.length() || j>=b.length())
        return 0;
    if(a[i]==b[j])
        return 1 + lcs_recursive(a,b,i+1,j+1);

    return max(lcs_recursive(a,b,i+1,j),lcs_recursive(a,b,i,j+1));
}

int lcs_dp(string a, string b){
    int dp[100][100];

    for(int j=0;j<b.length();j++){
        dp[0][j] = 0;
    }

    for(int i=0;i<a.length();i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            //cout << dp[i][j] << ' ';
        }

        //cout << endl;
    }

    return dp[a.length()][b.length()];
}

int main(){
    string a, b;
    cin >> a >> b;

    cout << lcs_dp(a,b);
    cout << endl << lcs_recursive(a,b,0,0);
}
