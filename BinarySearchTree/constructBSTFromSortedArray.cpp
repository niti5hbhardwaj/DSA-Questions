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

//https://youtu.be/C59kWTK4_Zs?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
Node* constructBSTFromSortedArray(vector<int> arr, int low, int high){
    if(low>high){
        return NULL;
    }
    int mid = (high+low)/2;
    Node* root = new Node(arr[mid]);
    root->left = constructBSTFromSortedArray(arr, low, mid-1);
    root->right = constructBSTFromSortedArray(arr, mid+1, high);
    return root;
}

void inOrder(Node* root){
    if(root== NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right); 
}

int main(){
    vector<int> arr{1,2,3,4,5,6};
    Node* root = NULL;
    root = constructBSTFromSortedArray(arr, 0, arr.size()-1) ;
    inOrder(root);
}