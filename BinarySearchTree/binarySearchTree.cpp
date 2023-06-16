#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int val){
    if(root == NULL){
        Node* n = new Node(val);
        return n;
    }
    if(val<root->data){
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right); 
}

Node* searchNode(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(key<root->data){
        return searchNode(root->left,key);
    } 
    return searchNode(root->right, key);
}

Node* inOrderSuccessor(Node* root){
    Node* temp = root;
    while(temp && temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root, int key){

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    } else if (key > root->data){
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL){
            Node* toDelete = root;
            root = root->right;
            delete toDelete;
            return root;
        } else if(root->right == NULL){
            Node* toDelete = root;
            root = root->left;
            delete toDelete;
            return root;
        }
        Node* temp = inOrderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    vector<int> values{1,3,4,2,7};
    Node* root = new Node(5);
    for(auto x: values){
        insertNode(root, x);
    }
    inOrder(root);
    cout<<endl;

    deleteNode(root, 4 );
    inOrder(root);
    cout<<endl;

}