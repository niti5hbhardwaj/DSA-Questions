#include<iostream>
#include<queue>
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

void leftView(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(NULL);
    q.push(root);
    
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            if(!q.empty()){
                cout<<q.front()->data<<" ";
                q.push(NULL);
            }

        } else {
            Node* current = q.front();
            q.pop();
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left =  new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    leftView(root);
}