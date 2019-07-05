// PROBLEM LINK: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// Graph Problem
#include<bits/stdc++.h>

using namespace std;

class graph{
    map<int, list<int>> adjList;
    int V;
public:
    graph(int n){
        V = n;
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        //V++;
    }

    int dfs(int i, map<int,bool> &visited){
        visited[i] = true;
        int ans = 1;
        for(auto neighbour:adjList[i]){
            if(!visited[neighbour]){
                ans += dfs(neighbour, visited);
            }
        }

        return ans;
    }

    void solve(){
        map<int,bool> visited;

        for(auto i:adjList){
            visited[i.first] = false;
        }

        int total = V*(V-1)/2;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                int country_size = dfs(i, visited);
                // cout << country_size << " \n";
                total -= country_size*(country_size-1)/2;
            }
        }

        cout << total;
    }
};

int main(){
    int n,p,x,y;
    cin>>n>>p;

    graph g(n);

    for(int i=0;i<p;i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }

    g.solve();
}
