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

    // BFS IMPLEMENTATION OF PROBLEM
    bool isCyclicBFS(T src){
        map<T, bool> visited;
        map<T, T> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto neighbour:adjList[node]){
                if(visited[neighbour]==true && parent[node] != neighbour){
                    return true;
                }

                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }

    bool isCyclicDFS_implement(T node, map<T,bool> &visited, map<T,bool> &inStack){
        visited[node] = true;
        inStack[node] = true;

        // Goto its neighbours/children
        for(auto neighbour:adjList[node]){
            if(visited[neighbour]==false && isCyclicDFS_implement(neighbour, visited, inStack)){
                return true;
            }

            else if(inStack[neighbour])
                return true;
        }

        return false;
    }

    bool isCyclicDFS(T src){
        map<T,bool> visited;
        map<T,bool> inStack;

        for(auto i:adjList){
            T node = i.first;

            if(!visited[node]){
                return isCyclicDFS_implement(node, visited, inStack);
            }
        }

        return false;
    }

};

int main(){

    graph<int> g;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);

    cout << g.isCyclicBFS(1) << "\n" << g.isCyclicDFS(1);
}
