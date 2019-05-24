#include<bits/stdc++.h>

using namespace std;

#define PRIME_KEY 37; // Can be any prime number, since Prime number as a modulo ____

template <class T>

class node{
    public:
        string key;
        T value;
        node<T> *next;

        node(string key, T v){
            this -> key = key;
            value = v;
        }

        ~node(){
            delete next;
        }
};
template <typename T>
class HashTable{
    int cs; // Current Array Size
    int ts; // Maximum Array Size
    node<T>** buckets;

    int hashFunc(string key){
        int L = key.length();
        int ans = 0;
        int power = 1;

        for(int i=0;i<L;i++){
            ans += key[L-i-1]*power;
            power *= PRIME_KEY;
            power %= ts;
            ans %= ts;
        }

        return ans;
    }

    void rehash(){
        node<T>** oldBuckets = buckets;

        int oldTS = ts;
        ts *= 2;
        cs=0;

        buckets = new node<T>*[ts];

        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }

        for(int i=0;i<oldTS;i++){
            node<T>* temp = oldBuckets[i];
            if(temp != NULL){
                while(temp != NULL){
                    insert(temp->key, temp->value);
                    temp = temp ->next;
                }
            }
            delete oldBuckets[i];
        }

        delete [] oldBuckets;
    }
    public:
        HashTable(int ds = 7){
            cs = 0;
            ts = ds;
            buckets =  new node<T>*[ts];

            for(int i=0;i<ts;i++){
                buckets[i] = NULL;
            }
        }

        void insert(string key, T v){
            // Hash Function to convert  key to index
            int i = hashFunc(key);

            node<T>* n = new node<T>(key,v);

            // Inserting at head
            n -> next = buckets[i];
            buckets[i] = n;

            cs++;

            float loadFactor = (float)cs/ts;

            if(loadFactor > 0.7){       // Threshold is taken as 0.7
                cout << "Load Factor: " << loadFactor << endl;
                rehash();
            }
        }

        void print(){
            for(int i=0;i<ts;i++){
                node<T>* temp = buckets[i];
                cout << "Bucket " << i << " -> ";

                while(temp != NULL){
                    cout << temp->key << " , ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        T* search(string key){
            int i = hashFunc(key);
            node<T>* temp = buckets[i];

            while(temp!=NULL){
                if(key == temp->key){
                    return &(temp->value);
                }
                temp = temp->next;
            }
            return NULL;
        }

        // Why use search when you can use []

        T& operator[](string key){
            T* temp = search(key);

            if(temp == NULL){
                T garbage_val;
                insert(key, garbage_val);
                T* value = search(key);
                return *value;
            }

            return *temp;
        }

        void erase(string key){
            int i = hashFunc(key);
            node<T>* temp = buckets[i];

            while(temp != NULL){
                if(temp->key == key){
                    cout << key << " is being deleted..." << endl;

                    node<T>* t2 = temp;
                    temp = temp ->next;
                    delete t2;
                    cout << "Deleted!" << endl;
                    return;
                }
            }

            cout << "Key not found" << endl;
        }
};
