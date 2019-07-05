#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    // First of pair stores node, the second of pair stores weight
    map<T, list<pair<T,int>>> adjList;

public:

    Graph(){
    }

    void addEdge(T u, T v, int weight, bool bidirectional=false){
        adjList[u].push_back(make_pair(v,weight));

        if(bidirectional==true){
            adjList[v].push_back(make_pair(u,weight));
        }

        return;
    }

    void bellman_ford(T src){
        map<T,int> dist;
        map<T,T> parent;

        int V = 0;

        for(auto i:adjList){
            dist[i.first] = INT_MAX;
            parent[i.first] = NULL;
            V++;
        }

        dist[src] = 0;


        // Relaxing edges V-1 times
        for(int i=0;i<V-1;i++){
            for(auto x:adjList){
                auto u = x.first;
                for(auto neighbour:adjList[u]){
                    auto v = neighbour.first;
                    int edge_weight = neighbour.second;

                    if(dist[v] > dist[u] + edge_weight){
                        dist[v] = dist[u] + edge_weight;
                        parent[v] = u;
                    }
                }
            }
        }

        // Check for negative weight cycle in the graph
        // We do that by relaxing one more time
        // If we get even lesser distance, such cycle exists
        for(auto x:adjList){
            auto u = x.first;
            for(auto neighbour:adjList[u]){
                auto v = neighbour.first;
                int edge_weight = neighbour.second;

                if(dist[v] > edge_weight + dist[u]){
                    cout << "Error: Negative Weight Cycle Present";
                    return;
                }
            }
        }

        for(auto i:adjList){
            cout << i.first << " is " << dist[i.first] << " units away \n";

            cout << "Path Followed : " << i.first << " <- ";

            auto dad = parent[i.first];

            while(dad != NULL){
                cout << dad << " <- ";
                dad = parent[dad];
            }

            cout << "\n";
        }

        return;
    }
};

int main(){

    Graph<int> g;

    g.addEdge(0,1,4);
    g.addEdge(1,2,-3);
    g.addEdge(0,2,5);
    g.addEdge(0,3,8);
    g.addEdge(2,4,4);
    g.addEdge(4,3,1);
    g.addEdge(3,4,2);

    g.bellman_ford(0);
}
