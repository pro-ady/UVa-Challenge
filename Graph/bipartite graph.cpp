#include<bits/stdc++.h>

using namespace std;

class graph{
    map<int,list<int>> adjList;
    int V;

public:
    graph(int n){
        V = n;
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // BFS Implementation
    bool isBipartite(int src){
        queue<int> q;

        q.push(src);

        // Colors can 'Colour 0' or 'Colour 1'
        int *colors = new int[V];

        for(int i=0;i<V;i++){
            // Unvisited Nodes initialisation
            colors[i] = -1;
        }

        colors[0] = 0;
        bool ans = true;

        while(!q.empty() && ans == true){
            int v = q.front();
            q.pop();

            for(auto neighbour:adjList[v]){
                if(colors[neighbour]==-1){
                    colors[neighbour] = 1 - colors[v];
                    q.push(neighbour);
                }

                else if(colors[neighbour] == colors[v]){
                    ans = false;
                    break;
                }
            }
        }

        return ans;
    }
};

int main(){
    graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout << g.isBipartite(0);

}
