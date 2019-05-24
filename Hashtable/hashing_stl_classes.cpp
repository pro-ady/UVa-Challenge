#include<bits/stdc++.h>

using namespace std;

class info{
    public:
        int id;
        string school;
        int iq;

        info(){
        }

        info(int id, string school, int iq){
            this->id = id;
            this->school = school;
            this->iq = iq;
        }
};

int main(){
    unordered_map<string, info> studentMap;
    info s(1,"DPS", 120);

    studentMap["Aditya"] = s;

    info s2 = studentMap["Aditya"];
    cout << s2.school;
}
