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
}
