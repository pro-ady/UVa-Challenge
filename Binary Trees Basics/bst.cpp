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

typedef pair<node*,node*> pnn;

node* insertBST(node* root, int data){

    if(root==NULL){
        root = new node(data);
        return root;
    }

    if(data<=root->data){
        root->left = insertBST(root->left, data);
    }

    else{
        root->right = insertBST(root->right, data);
    }

    return root;
}

void displayTree(node *root){
    if(root==NULL){
        return;
    }

    cout << root->data << " , ";
    displayTree(root->left);
    displayTree(root->right);
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

node* delete_BST(node* root, int key){
    if(root==NULL)
        return NULL;

    if(key < root->data){
        root->left = delete_BST(root->left, key);
        return root;
    }

    else if(key == root->data){
        // Node with 0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // Node with 1 child
        if(root->left == NULL && root->right){
            node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children

        // Looking for min element in right subtree
        // Also could've searched for max in left subtree
        node* mv_ptr = root->right;

        while(mv_ptr->left != NULL){
            mv_ptr = mv_ptr -> left;
        }

        root->data = mv_ptr->data;
        root->right = delete_BST(root->right, mv_ptr->data);

        return root;
    }

    else{
        root->right = delete_BST(root->right, key);
        return root;
    }
}

// Return pair <head, tail> of linked list
pair<node*, node*> flatten(node* root){
    pnn p;

    // Empty Node OR Leaf Node
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        p.first = p.second = root;
        return p;
    }

    // Only Left Subtree
    if(root->right==NULL && root->left){
        pnn leftLL = flatten(root->left);
        leftLL.second->right = root;

        p.first = leftLL.first;
        p.second = root;
        return p;
    }

    // Only Right Subtree
    if(root->right && root->left==NULL){
        pnn rightLL = flatten(root->right);
        root->right = rightLL.first;

        p.first = root;
        p.second = rightLL.second;

        return p;
    }


    pnn leftLL = flatten(root->left);
    pnn rightLL = flatten(root->right);

    leftLL.second->right = root;
    root->right = rightLL.first;

    p.first = leftLL.first;
    p.second = rightLL.second;

    return p;
}

int main(){
    node* root = NULL;
    int d;
    cin>>d;
    while(d != -1){
        root = insertBST(root, d);
        cin>>d;
    }

    cout << "\n\n";
    bfs_cool2(root);

    /*
    // DELETION
    cout << "\n\n Enter Node to be Deleted: ";
    cin>>d;

    root = delete_BST(root, d);

    cout << "\n\n";
    bfs_cool2(root);


    //FLATTEN
    pnn LinkedList = flatten(root);
    node* temp  = LinkedList.first;
    cout << "Linked List is:\n";
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->right;
    }
    */
}
