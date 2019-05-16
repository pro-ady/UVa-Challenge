#include<bits/stdc++.h>

using namespace std;

int main(){
    int first,second, third, start;

    cin >> start>>first>>second>> third;

    while(first || second || third || start){
        int ans = 1080 + ((start-first + 40)%40 + (second-first+40)%40 + (second - third + 40)%40)*9;

        cout << ans << endl;
         cin >> start>>first>>second>> third;

    }
}
