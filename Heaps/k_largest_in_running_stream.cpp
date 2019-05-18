#include<bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;

    int k,tmp;
    cin>>k;

    for(int i=0;i<k;i++){
        cin>>tmp;
        pq.push(tmp);
    }

    cin>>tmp;

    while(tmp!=-1){
        if(tmp > pq.top()){
            pq.pop();
            pq.push(tmp);
        }

        cin>>tmp;
    }

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}
