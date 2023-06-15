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

//https://youtu.be/WR6-DrAsNpc?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
void flattenTree(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        flattenTree(root->left);
        Node* rightSubtree = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* temp = root->right;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        temp->right = rightSubtree;
    }

    flattenTree(root->right);
}

void display(Node* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
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
    flattenTree(root);
    display(root);
}