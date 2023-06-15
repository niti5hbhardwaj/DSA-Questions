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

bool getPath(Node* root, int n, vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    if(getPath(root->left, n, path) || getPath(root->right, n, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int pointOfChange(vector<int> pathToFirst, vector<int> pathToSecond){
    for(int i=0;i<min(pathToFirst.size(), pathToSecond.size());i++){
        if(pathToFirst[i]!=pathToSecond[i] && i!=0){
            return pathToFirst[i-1];
        }
    }
    return -1;
}

int lowestCommonAncestor(Node* root, int n1, int n2){
    vector<int> pathToFirst;
    vector<int> pathToSecond;

    if(!getPath(root, n1, pathToFirst) || !getPath(root,n2,pathToSecond)){
        return -1;
    }

    int lca = pointOfChange(pathToFirst, pathToSecond);
    return lca;
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
    cout<<lowestCommonAncestor(root,5,9);
}