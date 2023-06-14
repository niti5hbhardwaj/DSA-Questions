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

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return (max(leftHeight, rightHeight) + 1);
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left) && isBalanced(root->right) && abs(heightOfTree(root->left) - heightOfTree(root->right))<=1){
        return true;
    }
    return false;
}

//optimised
//https://youtu.be/bh4eb_6SwRA?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=653
bool balanced(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;
    bool leftBalanced = balanced(root->left, &leftHeight);
    bool rightBalanced = balanced(root->right, &rightHeight);
    *height = max(leftHeight, rightHeight)+1;
    if(leftBalanced && rightBalanced && abs(leftHeight-rightHeight)<=1){
        return true;
    }
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left =  new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<balanced(root,&height)<<endl;
}