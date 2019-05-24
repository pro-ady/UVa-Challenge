#include<bits/stdc++.h>

using namespace std;

typedef unordered_map<int,int> uii;
typedef vector<int> vi;

int main(){
    vi v1,v2;
    uii Union, Intersect;
    int i;

    cin>>i;
    while(i != -1){
        v1.push_back(i);
        cin>>i;
    }

    cin>>i;
    while(i != -1){
        v2.push_back(i);
        cin>>i;
    }

    // UNION
    {

        for(auto i:v1){
            Union.insert(make_pair(i,0));
        }

        for(auto i:v2){
            Union.insert(make_pair(i,0));
        }
        cout << "Union: ";
        pair<int,int> *it;
        for(auto it=Union.begin(); it != Union.end(); it++){
            cout << it->first << ",";
        }
        cout << endl;
    }

    // Intersection
    {
        for(auto i:v1){
            Intersect.insert(make_pair(i,0));
        }
        cout << "Intersection: ";
        for(auto i:v2){
            if(Intersect.count(i)){
                cout << i << ",";
            }
        }
    }
}
