#include<bits/stdc++.h>

using namespace std;

int main(){
    int row, col,t;
    cin >> t;

    while(t--){
        cin >> row >> col;
        cout << floor(row/3) * floor(col/3) << endl;
    }
}
