/*  In order to implement the max heap simply reverse the conditions
    Or
    A simple tweak using compare(x,y) which gives different values when different
    types of heap are taken can be used

    EDIT: I found that this compare(x,y) is implemented in C++ using 'comparators'
*/
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class heap{
    vi v;

    void heapify(int index){
        int left=2*index;
        int right = 2*index+1;

        int min_index = index;

        if(left<v.size() && v[left] < v[index]){
            min_index = left;
        }

        if(right<v.size() && v[right] < v[min_index]){
            min_index = v[right];
        }

        if(min_index != index){
            swap(v[min_index], v[index]);
            heapify(min_index);
        }

        return;
    }

    public:
        heap(){
            v.push_back(-1);
        }

        bool empty(){
            return v.size()==1;
        }

        int top(){
            return v[1];
        }

        void insert(int x){
            v.push_back(x);
            int i = v.size()-1;

            while( i>=2 && v[i] < v[i/2]){
                swap(v[i],v[i/2]);
                i /= 2;
            }
        }

        void pop(){
            // Removing topmost element

            swap(v[1], v[v.size()-1]);
            v.pop_back();
            heapify(1);
        }

        void display(){
            for(int i=1;i<v.size();i++){
                cout << v[i] << " , ";
            }
        }
};

int main(){
    int a;
    heap h;

    cin>>a;

    while(a != -1){
        h.insert(a);
        cin>>a;
    }

    cout << "\n\n";
    h.display();
    cout << "\n\n";

    while(!h.empty()){
        h.pop();
        h.display();
        cout << "\n\n";
    }
}
