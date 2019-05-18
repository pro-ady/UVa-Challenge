#include<bits/stdc++.h>

using namespace std;

#define foi(L,U,j) for(int i=L;i<=U;i+=j)

int main(){
    // Max Heap
    priority_queue<int> pq1;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq2; // greater<int> is a built-in comparator

    int a[] = {12,1,4,6,3,5,9};
    int n = sizeof(a)/sizeof(a[0]);

    foi(0,n-1,1){
        pq1.push(a[i]);
        pq2.push(a[i]);
    }

    while(!pq1.empty()){
        cout << pq1.top() << " , ";
        pq1.pop();
    }

    cout << "\n\n";

    while(!pq2.empty()){
        cout << pq2.top() << " , ";
        pq2.pop();
    }
}
