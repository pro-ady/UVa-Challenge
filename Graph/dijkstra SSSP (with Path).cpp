#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    map<T, list<pair<T,int>>> adjList;

public:
    Graph(){
    }

    void addEdge(T u, T v, int dist, bool bidirection=true){
        adjList[u].push_back(make_pair(v,dist));
        if(bidirection){
            adjList[v].push_back(make_pair(u,dist));
        }
        return;
    }

    void print(){

        for(auto i:adjList){
            cout << i.first << " -> ";

            for(auto node:i.second){
                cout << "(" << node.first << "," << node.second << ") , ";
            }

            cout << "\n";
        }
    }

    void dijkstraSSSP_with_path(T src){

        // Create Min Heap to keep track of minimum distances
        priority_queue<pair<int,T>, vector<pair<int,T>>, greater<pair<int,T>>> pq;

        // Keep map for distances
        map<T, int> dist;

        // Keep map for remembering parents
        map<T,T> parent;

        for(auto i:adjList){
            dist[i.first] = INT_MAX;
            parent[i.first] = NULL;
        }

        dist[src] = 0;
        pq.push(make_pair(0,src));

        while(!pq.empty()){
            auto curr = pq.top().second;
            pq.pop();

            for(auto neighbour:adjList[curr]){
                T node = neighbour.first;
                int weight = neighbour.second;

                if(dist[node] > dist[curr] + weight){
                    dist[node] = dist[curr] + weight;
                    pq.push(make_pair(dist[node], node));
                    parent[node] = curr;
                }
            }
        }

        for(auto i:adjList){
            cout << i.first << " is " << dist[i.first] << " units away \n";
            cout << "Path Taken - " << i.first << "<-";
            auto dad = parent[i.first];

            while(dad != NULL){
                cout << dad << "<-";
                dad = parent[dad];
            }

            cout << "\n";
        }
    }
};

int main(){
    Graph<char> g;
    g.addEdge('A','B', 5);
    g.addEdge('A','D', 9);
    g.addEdge('A','E', 2);
    g.addEdge('E','F', 3);
    g.addEdge('D','F', 2);
    g.addEdge('D','C', 3);
    g.addEdge('B','C', 2);

    g.print();

    cout << "\n\n";

    g.dijkstraSSSP_with_path('A');
}
