#include<bits/stdc++.h>

using namespace std;

// 1st -> Value.....(2nd, 3rd) gives index in 2D Array
typedef pair<int, pair<int,int>> ppi;

void merge_arrays(vector<vector<int>> v){
    vector<int> output;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for(int i=0;i<v.size();i++){
        pq.push({v[i][0], {i,0}});
    }

    while(!pq.empty()){
        ppi current_element= pq.top();

        output.push_back(current_element.first);
        pq.pop();

        int i = current_element.second.first;
        int j = current_element.second.second;

        j = j + 1;

        if(j<v[i].size()){
            pq.push({v[i][j], {i,j}});
        }
    }

    for(int i=0;i<output.size();i++){
        cout << output[i] << " ";
    }
}

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;

    int k, n, temp;
    cin>>k>>n;

    vector<vector<int>> a;

    for(int i=0;i<k;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            cin>>temp;
            row.push_back(temp);
        }
        a.push_back(row);
    }

    merge_arrays(a);
}
