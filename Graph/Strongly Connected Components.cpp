// Strongly connected component in a graph is a component such that every vertex that is
// reachable by this component, can also reach this component
#include<bits/stdc++.h>

using namespace std;

bool found(list<int> x, int y){
    if(find(x.begin(), x.end(), y) == x.end())
        return false;
    return true;
}

class graph{
    int V;
public:
    map<int, list<int>> adjList;

    graph(){
        //this->V = V;
    }

    void addEdge(int v, int w, bool bidirectional=false){
        adjList[v].push_back(w);
        if(bidirectional)
            adjList[w].push_back(v);
    }

    void dfs(int src, map<int,bool> &visited, stack<int> &stck){
        visited[src] = true;
        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,stck);
            }
        }
        //cout << src << "<-";
        stck.push(src);
    }

    void dfs_for_reverse(int src, map<int,bool> &visited, set<int> &result){
        visited[src] = true;
        result.insert(src);

        for(auto i:adjList[src]){
            if(!visited[i]){
                dfs_for_reverse(i,visited,result);
            }
        }
    }

    map<int,list<int>> reverseGraph(){
        map<int,list<int>> temp;

        for(auto i:adjList){
            auto v = i.first;
            //cout << v << "->";
            for(auto neighbour:adjList[v]){
                //cout << neighbour << ",";
                temp[neighbour].push_back(v);
            }
        }

        return temp;
    }

    vector<set<int>> stronglyCC(){
        // Stack to store numbers in order of finish time in reverse order
        stack<int> stck;

        map<int,bool> visited;

        for(auto i:adjList){
            //cout << i.first << " ";
            visited[i.first] = false;
        }

        //cout << endl << endl;

        for(auto i:adjList){
            auto v = i.first;
            if(!visited[v]){
                //cout << v << endl;
                dfs(v,visited,stck);
            }
            //cout << endl;
        }

        adjList = reverseGraph();

        for(auto i:adjList){
            visited[i.first] = false;
        }

        vector<set<int>> ans;

        while(!stck.empty()){
            auto v = stck.top();
            stck.pop();
            //cout << v <<",";
            if(!visited[v]){
                set<int> temp_set;
                dfs_for_reverse(v,visited,temp_set);
                ans.push_back(temp_set);
                continue;
            }
        }

        return ans;
    }
};

int main(){
    graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,5);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(7,6);
    cout << "\n\n\n";
    for(auto set_i:g.stronglyCC()){
        cout << "{";
        for(auto element:set_i){
            cout << element << ",";
        }
        cout << "}";
    }
}
