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

Node* constructBSTUtil(vector<int> preOrder, int* preOrderIndex, int key, int min, int max){
    if(*preOrderIndex > preOrder.size()){
        return NULL;
    }

    Node* root = NULL;

    if(key > min && key < max){
        root = new Node(key);
        *preOrderIndex += 1;

        if(*preOrderIndex < preOrder.size()){
            root->left = constructBSTUtil(preOrder, preOrderIndex, preOrder[*preOrderIndex], min, key);
        }

        if(*preOrderIndex < preOrder.size()){
            root->right = constructBSTUtil(preOrder, preOrderIndex, preOrder[*preOrderIndex], key, max);
        }
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

Node* constructBST(vector<int> preOrder){
    int preOrderIndex = 0;
    int min = INT_MIN;
    int max = INT_MAX;
    int key = preOrder[0];
    return constructBSTUtil(preOrder, &preOrderIndex, key, min, max);
}

int main(){
    vector<int> preOrder{7,5,4,6,8,9};
    Node* root = constructBST(preOrder);
    inOrder(root);
}