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

//https://youtu.be/xDayqPCWmkY?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
void sumReplacement(Node* root){
    if(root==NULL){
        return;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left!=NULL){
        root->data+= root->left->data;
    }
    if(root->right!=NULL){
        root->data+= root->right->data;
    }
    return; 
}

void levelOrder(Node* root){
    if(root==NULL){
        return; 
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
    }
    return;
}

int main(){
    Node* root = new Node(1);
    root->left =  new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrder(root);
    sumReplacement(root);
    cout<<endl<<endl;
    levelOrder(root);

}