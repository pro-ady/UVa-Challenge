#include<bits/stdc++.h>

using namespace std;

template<typename T>

class graph{
    map<T, list<T>> adjList;

public:
    Graph(){
    }

    void addEdge(T u, T v, bool bidirection=false){
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

    // DONOT Forget to Pass map and list by reference
    // DON'T PASS BY VALUE
    void dfs_implement(T node, map<T,bool> &visited, list<T> &ordering){
        visited[node] = true;

        for(auto neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfs_implement(neighbour, visited, ordering);
            }
        }

        ordering.push_front(node);
    }

    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;

        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                dfs_implement(node, visited, ordering);
            }
        }

        for(auto i:ordering){
            cout << i << " -> ";
        }
    }
};

int main(){

    graph<string> g;

    g.addEdge("Unnati", "English");
    g.addEdge("Unnati", "Computer Basics");
    g.addEdge("English", "Computer Basics");
    g.addEdge("Computer Basics", "Programming");
    g.addEdge("English", "Books");
    g.addEdge("Books", "Programming");

    g.dfsTopologicalSort();


}
