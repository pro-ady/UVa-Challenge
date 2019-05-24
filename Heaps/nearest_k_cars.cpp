/*
    Given N cars and their coordinates find the nearest K cars
*/
#include<bits/stdc++.h>

using namespace std;

class car{
    public:
        int x;
        int y;
        int model;

        car(int x, int y, int model){
            this->x = x;
            this->y = y;
            this->model = model;
        }

        int dis2_from_O(){
            return x*x + y*y;   // Considering Euclidean Distance
        }
};

class carCompare{
    public:
        // Method to overload ()
        bool operator()(car a, car b){
            return a.dis2_from_O() > b.dis2_from_O(); // FOR MIN HEAP
        }
};

int main(){
    /*  with this
            priority_queue<car> pq;
        the pq doesn't know what to prioritize when ranking cars, hence an error

        Hence we use functor class carCompare in this case to make comparisons
    */
    priority_queue<car, vector<car>, carCompare> pq;

    pair <int, int> p[10] = {{2, 18},{3, 21},{7, 2},{11, 8},{13, 28},{16, 26},{18, 9},{28, 15},{28, 24},{30, 14}};

    for(int i=0;i<10;i++){
        car c(p[i].first, p[i].second, 10);
        pq.push(c);
    }

    while(!pq.empty()){
        cout << "(" << pq.top().x << "," << pq.top().y << ") , ";
        pq.pop();
    }
}
