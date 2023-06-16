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


//https://youtu.be/_XgTN72fguk?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
bool checkBST(Node* root, Node* min, Node* max){
    if(root==NULL){
        return true;
    }
    
    if( min!=NULL && root->data <= min->data){
        return false;
    }
    if( max!= NULL && root->data >= max->data){
        return false;
    }

    bool leftBalanced = checkBST(root->left, min, root);
    bool rightBalanced = checkBST(root->right, root, max);

    return (leftBalanced && rightBalanced);

}

int main(){
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    cout<<checkBST(root, NULL, NULL)<<endl;
}