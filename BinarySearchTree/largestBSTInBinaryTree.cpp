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

struct NodeInfo{
    int min = INT_MAX;
    int max = INT_MIN;
    int size = 0;
    int maxSize = 0;
    bool isBST = true;
};

NodeInfo largestBSTInBinaryTree(Node* root){
    if(root==NULL){
        NodeInfo currentTree;
        return currentTree;
    }

    //checking for left node
    if(root->left==NULL && root->right==NULL){
        NodeInfo currentTree;
        currentTree.min = currentTree.max = root->data;
        currentTree.size = currentTree.maxSize = 1;
        return currentTree;
    }

    NodeInfo leftSubtree = largestBSTInBinaryTree(root->left);
    NodeInfo rightSubtree = largestBSTInBinaryTree(root->right);

    NodeInfo currentTree;
    currentTree.size = (1 + leftSubtree.size + rightSubtree.size);

    if(leftSubtree.isBST && rightSubtree.isBST && leftSubtree.max < root->data && root->data < rightSubtree.min){
        currentTree.min = min(root->data, leftSubtree.min);
        currentTree.max = max(root->data, rightSubtree.max) ;
        currentTree.maxSize = currentTree.size;
        currentTree.isBST = true;

        return currentTree;
    }
    currentTree.maxSize = max(leftSubtree.maxSize, rightSubtree.maxSize);
    currentTree.isBST = false;

    return currentTree;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(1);
    root->left->right = new Node(4);
    
    root->right = new Node(3);
    root->right->right = new Node(10);
    // root->right->right->left = new Node(9);
    // root->right->right->left->left = new Node(8);
    NodeInfo tree = largestBSTInBinaryTree(root);
    cout<<tree.maxSize<<endl;
}
