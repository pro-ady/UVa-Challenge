#include<bits/stdc++.h>
#include"hashtable.h"

using namespace std;

int main(){
    HashTable<int> h(7);

    h.insert("mango", 100);
    h.insert("apple", 200);
    h.insert("orange", 300);
    h.insert("squash", 400);
    h.insert("berries", 150);
    h.insert("lime", 130);
    h.insert("grape", 120);
    h.insert("guava", 170);
    h.print();

    string f = "mango";
    int *price = h.search(f);

    cout << *price << endl;

    h.erase("orange");

    cout << h["lime"];
    //cout<<endl<<endl;
    //h.print();
}
