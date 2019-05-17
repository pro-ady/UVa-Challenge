#include<bits/stdc++.h>

using namespace std;

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

// Coded in bfs.cpp
void bfs_cool2(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        if(q.front()==NULL){
            cout << endl;
            q.pop();

            if(!q.empty())
                q.push(NULL); // End of one level

            continue;
        }

        node* temp = q.front();
        cout << temp->data << " , ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }

    }
}

int sumTree(node* root){
    if(root == NULL){
        return 0;
    }

    if(!(root->left || root->right)){
        return root->data;
    }

    int lsum = sumTree(root->left);
    int rsum = sumTree(root->right);

    int temp = root->data;

    root->data = lsum + rsum;

    return (lsum + rsum + temp);
}

int main(){
    node *root = create_Tree(root);

    int formality = sumTree(root);

    cout << "\n\n";

    bfs_cool2(root);
}
