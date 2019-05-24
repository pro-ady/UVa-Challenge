#include<bits/stdc++.h>

using namespace std;

int main(){
    // unordered_map<key, value> myMap;

    unordered_map<string, int> newMap;

    // Insertion
    newMap["Mango"] = 100;
    newMap.insert(make_pair("Apple", 170));

    pair<string,int> p{"Grape", 130};
    newMap.insert(p);


    // Print
    for(auto node:newMap){  // Since C++11
        cout << node.first << " " << node.second << endl;
    }


    // Iterate over buckets
    for(int i=0; i<newMap.bucket_count();i++){
        cout << "Bucket " << i << ": ";

        for(auto it = newMap.begin(i); it != newMap.end(i); it++){
            cout << it->first << " " << it->second;
        }

        cout << endl;
    }


    // Count Function : Returns 1 if found and 0 if not found
    cout << newMap.count("Apple") << endl << newMap.count("Banana");
}
