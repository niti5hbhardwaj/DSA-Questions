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

int maxSumPath(Node* root){
    if(root==NULL){
        return 0;
    }

    int current = root->data;
    int leftSubtree = maxSumPath(root->left);
    int rightSubtree = maxSumPath(root->right);

    int subtreeMax = max(leftSubtree, rightSubtree);

    return max(current+subtreeMax, current);
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

    cout<<maxSumPath(root);
}