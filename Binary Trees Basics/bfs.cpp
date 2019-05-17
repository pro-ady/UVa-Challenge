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

void bfs(node* root){
    queue<node*> q;

    q.push(root);

    while(!q.empty()){
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

void bfs_cool(node* root){
    queue<pair<node*, int>> q; // Queue of pairs to maintain root and its level

    int level = height_node(root);
    q.push(make_pair(root,level));

    while(!q.empty()){
        int level2 = q.front().second;

        if(level != level2){
            level = level2;
            cout << endl;
        }

        node *temp = q.front().first;
        cout << temp -> data << " , ";
        q.pop();

        if(temp->left){
            q.push(make_pair(temp->left, level-1));
        }

        if(temp->right){
            q.push(make_pair(temp->right, level-1));
        }

    }
}

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

int main(){
    node *root = create_Tree(root);

    cout << "\n\n";

    bfs(root);

    cout << "\n\n";

    bfs_cool(root);

    cout << "\n\n";

    bfs_cool2(root);
}
