// Given an input stream and an expected output stream,
// Decide the minimum cost of changing the input to output
// Given it costs a single unit to insert, replace, delete a single character
#include<bits/stdc++.h>

using namespace std;

int min_edit_cost_recursive(string a, string b, int i, int j){
    if(i >= a.length() || j >= b.length())
        return 0;

    if(a[i] == b[j]){
        return min_edit_cost_recursive(a,b,i+1,j+1);
    }

    int ins = min_edit_cost_recursive(a,b,i,j+1) + 1;
    int del = min_edit_cost_recursive(a,b,i+1,j) + 1;
    int rep = min_edit_cost_recursive(a,b,i+1,j+1) + 1;

    return min(min(ins,del),rep);
}

int min_edit_cost_dp(string in, string out){
    int dp[100][100] = {};
    dp[0][0] = 0;

    // Changing 'nothing' to output
    for(int j=1; j<=out.length();j++){
        dp[0][j] = 1 + dp[0][j-1];
    }

    // Changing input to 'nothing'
    for(int i=1;i<in.length();i++){
        dp[i][0] = 1 + dp[i-1][0];
    }

    // Filling the table iteratively
    for(int i=1;i<=in.length();i++){
        for(int j=1;j<=out.length();j++){
            int ins = 1 + dp[i][j-1];
            int repl = 1 + dp[i-1][j-1];
            int del = 1 + dp[i-1][j];

            dp[i][j] = min(min(ins,repl),del);

            // But there is one mistake above
            // We haven't compensated for the case wherein the corresponding characters are same
            // In that case no work needs to be done in changing the Input to Output
            dp[i][j] -= (in[i] == out[j]) ? 1 : 0;
        }
    }

    // Cost of changing input to output
    return dp[in.length()][out.length()];
}

int main(){
    string inp, out;

    cin >> inp >> out;

    cout << min_edit_cost_recursive(inp,out,0,0);

    cout << endl << min_edit_cost_dp(inp, out);
}
