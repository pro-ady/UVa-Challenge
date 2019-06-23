// Given a 1 to N Snakes and Ladders boards,
// starting and ending points of all Snakes and Ladders
// Find out the minimum number of dice throws to win the game

// Dice throw results in number from 1 to 6
#include<bits/stdc++.h>

using namespace std;
template<typename T>

// Derived from graph_implementation.cpp with modified bfs_with_distance() arguments
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

    int bfs_with_distance(T src, T dest){
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

                // Minor optimization
                if(neighbour==dest){
                    break;
                }
            }
        }

        // OUTPUT ALL DISTANCE
        /*for(auto i:adjList){
            T node = i.first;

            cout << "Distance of " << node << " from " << src << " = " << dist[node] << endl;
        }*/

        return dist[dest];
    }
};

int main(){
    int n = 36;

    // Maintain a board array
    int board[n+50] = {0};

    // Example Board with '-' sign denoting snake
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    graph<int> g;

    for(int i=0;i<=n-1;i++){
        for(int dice=1;dice<=6;dice++){
            int v = i + dice + board[i+dice];
            g.addEdge(i,v,false);
        }
    }

    cout << "Shortest distance = " << g.bfs_with_distance(0,35) << endl;
}
