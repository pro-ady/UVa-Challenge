#include<bits/stdc++.h>

using namespace std;

// UNION - FIND DS
map<int,int> parent;

// Find the parent of a node
int find(int x){
    if(parent[x] == x)
        return x;

    return find(parent[x]);
}

// 'Unionise' 2 Sets ... i.e. Find the parent of parent of... of a node
void union_parent(int x, int y){
    parent[find(y)] = find(x);
}

// UNION - FIND DS with rank and path compression
map<int, int> rank_node;

int find2(int x){
    if(parent[x] == -1){
        return x;
    }

    return find(parent[x]);
}

int union_parent_2(int x, int y){
    int parent_x = find2(x);
    int parent_y = find2(y);

    if(rank_node[x] >= rank_node[y]){
        rank_node[x]++;
        parent[parent_y] = parent_x;
    }

    else{
        rank_node[y]++;
        parent[parent_x] = parent_y;
    }
}

class graph{
    // List of Edges
    vector<pair<int, pair<int,int>>> edges;
    int V,E;
public:
    graph(int V, int E){
        this->V = V;
        this->E = E;
    }

    void addEdge(int v, int w, int weight, bool bidirection=true){
        edges.push_back(make_pair(weight, make_pair(v,w)));
    }

    void Kruskal(){
        // mst_ni is edge index
        int mst_weight=0, mst_edges=0, mst_ni=0;

        // Sorting the edges according to weight
        sort(edges.begin(), edges.end());

        // Main Algo body
        while((mst_edges < V-1) || (mst_ni < E)){
            int v = edges[mst_ni].second.first;
            int w = edges[mst_ni].second.second;

            int weight = edges[mst_ni].first;

            // Check if including the edge v->w creates a cycle
            // i.e. if v,w are in different trees
            if(find(v) != find(w)){
                union_parent_2(v,w);

                mst_weight += weight;

                // Print the edge
                cout << v << " -- " << w << " , weight=" << weight << endl;

                mst_edges++;
            }

            mst_ni++;
        }

        cout << "MST of Weight = " << mst_weight << endl;
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    graph g(n,m);

    for(int i=1;i<=n;i++){
        parent[i] = i;
    }


    for(int i=1;i<=m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        g.addEdge(a,b,w);
    }

    g.Kruskal();
}
