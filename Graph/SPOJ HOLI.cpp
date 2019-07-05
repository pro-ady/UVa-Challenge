/*
Nowadays, people have many ways to save money on accommodation when they are on vacation. One of these ways is exchanging houses with other people.

Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:

All the people should go to one of the other people's city.
Two of them never go to the same city, because they are not willing to share a house.
They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.

Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.
*/
#include<bits/stdc++.h>

using namespace std;

class graph{
    list<pair<int,int>> *l;
    int V;

public:
    graph(int n){
        V = n;
        l = new list<pair<int,int>> [V];
    }

    void addEdge(int u, int v, int weight, bool bidirectional=true){
        l[u].push_back(make_pair(v,weight));

        if(bidirectional){
            l[v].push_back(make_pair(u,weight));
        }
    }

    int dfs(int src, bool* visited, int* count_subtree, int &ans){
        visited[src] = true;
        count_subtree[src] = 1;

        for(auto x:l[src]){
            auto neighbour = x.first;
            if(!visited[neighbour]){
                count_subtree[src] += dfs(neighbour, visited, count_subtree, ans);
                int y = count_subtree[neighbour];
                ans += 2*min(y,V-y)*(x.second);
            }
        }

        return count_subtree[src];
    }

    void solve(){
        bool *visited = new bool[V]{0};
        int *count_subtree = new int[V]{0};

        int ans = 0;
        dfs(0, visited, count_subtree,ans);

        /*for(int i=0;i<V;i++){
            cout << i << " : " << count_subtree[i] << endl;
        }*/

        cout << ans << endl;
    }

};

int main(){
    int t,i=1;
    cin>>t;
    while(t--){
        int n;
        cin >> n;

        graph g(n);

        for(int i=0;i<n-1;i++){
            int x,y,z;
            cin>>x>>y>>z;

            g.addEdge(--x,--y,z);
        }
        cout << "Case #" << i++ << " ";
        g.solve();
    }
}
