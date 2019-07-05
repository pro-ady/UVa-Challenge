// Given N cities which are connected via flight and train
// and Given the cost of each train and flight journey
// Compute the minimum fare that will be incurred if at most 1 flight is taken

#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    // Changed template to string because weird error encountered
    // string -> list(string, train, flight)
    map<string,list<pair<string,pair<int,int>>>> adjList;

public:

    Graph(){
    }

    void addEdge(string u, string v, int train, int flight, bool bidirectional=true){
        adjList[u].push_back(make_pair(v,make_pair(train,flight)));

        if(bidirectional){
            adjList[v].push_back(make_pair(u,make_pair(train,flight)));
        }

        return;
    }

    map<T,int> minimise_cost(T src){
        // Create Min Heap to keep track of minimum distances
        priority_queue<pair<int,T>, vector<pair<int,T>>, greater<pair<int,T>>> pq;

        // Keep map for distances
        map<T, int> dist;

        // Keep map for remembering parents
        // map<T,T> parent;

        for(auto i:adjList){
            dist[i.first] = INT_MAX;
            // parent[i.first] = NULL;
        }

        dist[src] = 0;
        pq.push(make_pair(0,src));

        while(!pq.empty()){
            auto curr = pq.top().second;
            pq.pop();

            for(auto neighbour:adjList[curr]){
                T node = neighbour.first;
                int weight = (neighbour.second).first;

                if(dist[node] > dist[curr] + weight){
                    dist[node] = dist[curr] + weight;
                    pq.push(make_pair(dist[node], node));
                    parent[node] = curr;
                }
            }
        }

        return dist;
    }

    int min_fare(string src, string dest){
        map<string, int> dist1 = minimise_cost(src);
        map<string, int> dist2 = minimise_cost(dest);

        // When no flights taken

    }
};
