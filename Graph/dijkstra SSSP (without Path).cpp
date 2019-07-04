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

    void dijkstraSSSP(T src){
        // To maintain the distance of nodes from source
        map<T,int> dist;

        // Initially all distances except for source are infinity
        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }

        dist[src] = 0;

        // Set to find out minimum distance node
        // Set is sorted according to first parameter

        set<pair<int,T>> s;

        s.insert(make_pair(0,src));

        while(!s.empty()){
            //
            auto p = *(s.begin());
            T node = p.second;
            int nodeDistance = p.first;

            s.erase(s.begin());

            // Iterate over its neighbours of present node
            for(auto neighbour:adjList[node]){
                if(nodeDistance + neighbour.second < dist[neighbour.first]){
                    T dest = neighbour.first;
                    auto x = s.find(make_pair(dist[dest], dest));

                    if(x != s.end()){
                        s.erase(x);
                    }

                    // Insert new pair
                    dist[dest] = nodeDistance + neighbour.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }

        for(auto d:dist){
            cout << d.first << " = " << d.second << " units away \n";
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

    g.dijkstraSSSP('A');
}
