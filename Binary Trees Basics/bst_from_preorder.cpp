#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int x){
            data = x;
            left = right = NULL;
        }
};

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

node* create_PreIn_BST(int *pre, int* in, int s, int e){
    static int i = 0; // To keep track of Preorder Array Index
    int index=-1; // To keep track of index of node in InOrder Array corresponding to ith index of PreOrder Array

    if(s>e){
        return NULL;
    }

    node* root = new node(pre[i]);

    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = create_PreIn_BST(pre, in, s, index-1);
    root->right = create_PreIn_BST(pre, in, index+1, e);

    return root;
}

node* create_PostIn_BST(int *post, int *in, int s, int e){
    static int i = e;

    if(s>e){
        return NULL;
    }

    node* root = new node(post[i]);

    int index = -1;
    for(int j=s; j<=e;j++){
        if(post[i]==in[j]){
            index = j;
            break;
        }
    }

    i--;

    root->left = create_PostIn_BST(post, in, s, index-1);
    root->right = create_PostIn_BST(post, in, index+1, e);

    return root;
}

int main(){
    // Chose Tree Beforehand Just for Easiness
    int in[] = {4,2,6,5};
    int pre[] = {6,4,2,5};
    int post[] = {2,4,5,6};
    int n = sizeof(in)/sizeof(int);

    node* root1 = create_PreIn_BST(pre, in, 0, n-1);

    bfs_cool2(root1);

    cout << "\n\n";

    node* root2 = create_PostIn_BST(post, in, 0, n-1);
    bfs_cool2(root2);
}
