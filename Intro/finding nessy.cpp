#include<bits/stdc++.h>

using namespace std;

int main(){
    int row, col,t;
    cin >> t;

    while(t--){
        cin >> row >> col;
        cout << (row/3) * (col/3) << endl;
    }
}
