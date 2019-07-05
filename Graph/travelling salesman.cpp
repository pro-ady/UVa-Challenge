#include<bits/stdc++.h>

using namespace std;

class graph{
    map<int, list<pair<int,int>>> adjList;

public:
    graph(){
    }

    void addEdge(int u, int v, int weight, bool bidirectional=true){
        adjList[u].push_back(make_pair(v,weight));

        if(bidirectional){
            adjList[v].push_back(make_pair(u,weight));
        }
    }

    int tsp(){
        map<int, int> minCostDP;
        map<int, int> parent;


    }
};
