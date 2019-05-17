#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

class node{
public:
    int data;
    node* right;
    node* left;

    node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

node* create_Tree(node *root){

    int data;
    cin >> data;
    if(data == -1)
        return NULL;

    root = new node(data);

    root->left = create_Tree(root->left);
    root->right= create_Tree(root->right);

    return root;
}

int height_node(node* root){
    if(root == NULL){
        return 0;
    }

    return max(height_node(root->left), height_node(root->right)) + 1;
}

pii diameter(node* root){
    pii p;

    if(root == NULL){
        p.first = p.second = 0;
        return p;
    }

    pii left = diameter(root->left);
    pii right = diameter(root->right);

    p.second = max(left.second, right.second) + 1;
    p.first = max(left.second+right.second+1, max(left.first, right.first));

    return p;
}

int main(){
    node* root;
    root = create_Tree(root);

    cout << "\n\n" << diameter(root).first;
}
