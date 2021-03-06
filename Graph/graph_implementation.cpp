#include<bits/stdc++.h>

using namespace std;

template<typename T>

class graph{
    map<T, list<T>> adjList;

public:
    Graph(){
    }

    void addEdge(T u, T v, bool bidirection=true){
        adjList[u].push_back(v);
        if(bidirection){
            adjList[v].push_back(u);
        }

        return;
    }

    void print(){

        for(auto i:adjList){
            cout << i.first << " -> ";

            for(auto node:i.second){
                cout << node << ",";
            }

            cout << "\n";
        }
    }

    void bfs(T src){
        queue<T> q;

        // Hash Map to keep track of visited nodes
        map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            cout << q.front() << " , ";
            T curr_node = q.front();
            q.pop();

            for(auto children:adjList[curr_node]){
                if(!visited[children]){
                    visited[children] = true;
                    q.push(children);
                }
            }
        }
    }

    // BFS with distance calculations

    void bfs_with_distance(T src){
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;

        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            //cout << node << " , ";
            q.pop();

            for(auto neighbour:adjList[node]){
                if(dist[neighbour] == INT_MAX){
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }

        // OUTPUT ALL DISTANCE
        for(auto i:adjList){
            T node = i.first;

            cout << "Distance of " << node << " from " << src << " = " << dist[node] << endl;
        }
    }

    void dfs_implement(T src, map<T,bool> visited){
        cout << src << ",";
        visited[src] = true;

        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                dfs_implement(neighbour, visited);
            }
        }
    }

    void dfs(T src){
        map<T, bool> visited;
        dfs_implement(src, visited);

        cout << endl;

        // Looking for Graph not connected to the initial tree;
        // i.e. Traversing Entire Forest
        int count_components = 1;
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                dfs_implement(node, visited);
                count_components++;
            }
        }

        cout << "Graph has " << count_components << " components" << endl;
    }
};

int main(){

    graph<string> g;

    g.addEdge("Plants", "Grasshopper", false);
    g.addEdge("Plants", "Squirrel", false);
    g.addEdge("Grasshopper", "Scorpian", false);
    g.addEdge("Scorpian","Fox", false);
    g.addEdge("Squirrel", "Fox", false);
    g.addEdge("Squirrel", "Eagle", false);
    g.addEdge("Fox", "Eagle");

    g.print();

    cout << "\n\n\n";

    g.bfs("Plants");

    cout << "\n\n\n";

    g.bfs_with_distance("Plants");

    cout << "\n\n\n";

    g.dfs("Plants");
}
