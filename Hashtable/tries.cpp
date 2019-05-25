#include<bits/stdc++.h>

using namespace std;

#define hashmap unordered_map<char, node*>

class node{
    public:
        char data;
        hashmap h;
        bool isTerminal;

        node(char d){
            data = d;
            isTerminal = false;
        }
};

class trie{
    node* root;
    public:
        trie(){
            root = new node('\0');
        }

        // Insertion
        void addWord(char *word){
            node* temp = root;

            for(int i=0;word[i] != '\0'; i++){
                char ch = word[i];

                if(temp->h.count(ch)==0){
                    node* child = new node(ch);
                    temp->h[ch] = child;
                    temp = child;
                }

                else{
                    temp = temp->h[ch];
                }
            }

            temp->isTerminal = true;
        }

        // Search/Lookup

        bool search(char *word){
            node* temp = root;
            for(int i=0;word[i]!='\0';i++){
                char ch = word[i];

                if(temp->h.count(ch) != 0){ // FIX ERROR HERE
                    temp = temp->ch;
                }

                else{
                    return false;
                }
            }

            return temp->isTerminal;
        }
};
