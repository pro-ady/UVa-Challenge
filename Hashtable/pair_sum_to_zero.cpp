#include<bits/stdc++.h>

using namespace std;
typedef unordered_map<int,int> uii;


int main(){
    uii myMap;
    int i;

    cin>>i;

    while(i!=-1){
        cin>>i;
        myMap.insert(i,0);
    }


    for(auto i:myMap){
        if(i.second != 0){
            continue;
        }

        if(myMap.count(i.first*(-1)) != 0){
            i.second = -1;
            myMap[i.first*(-1)] = -1;

            cout << i.first << " " << i.first*(-1) << endl;
        }
    }
}
