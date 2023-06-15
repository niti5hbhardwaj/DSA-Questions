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

//https://youtu.be/E1f9ncPxgPE?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
Node* lowestCommonAncestor(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = lowestCommonAncestor(root->left, n1, n2);
    Node* right = lowestCommonAncestor(root->right, n1, n2);

    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right == NULL){
        return NULL;
    }
    if(left!=NULL){
        return left;
    }
    if(right!=NULL){
        return right;
    }
    return NULL;
}

int findDistance(Node* root, int n){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int left = findDistance(root->left,n);
    int right = findDistance(root->right, n);
    if(left==-1 && right==-1){
        return -1;
    }
    return max(left, right)+1;
}

int shortestDistance(Node* root, int n1, int n2){
    Node* lca = lowestCommonAncestor(root, n1, n2);
    int d1 = findDistance(lca, n1);
    int d2 = findDistance(lca, n2);

    return d1+d2;
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
    cout<<shortestDistance(root, 9, 9)<<endl;
}