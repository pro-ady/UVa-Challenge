// Calculate the longest increasing subsequence in an integer array
#include<bits/stdc++.h>

using namespace std;

int len_dp(int a[], int n){
    int dp[100];

    fill(dp,dp+n,1);
    cout << dp[0] << " ";
    for(int i=1;i<n;i++){
        int max_len = 1;
        int index = i-1;

        while(index>=0){
            if(a[index] <= a[i]){
                int temp_len = 1 + dp[index];
                if(temp_len > max_len)
                    max_len = temp_len;
            }

            index--;
        }

        dp[i] = max_len;
        cout << dp[i] << " ";
    }

    return *(max_element(dp,dp+n));
}

int main(){
    int a[] = {10,22,9,33,21,50,41,60,80,6};
    int n = sizeof(a)/sizeof(a[0]);

    cout << endl << len_dp(a,n);
}
