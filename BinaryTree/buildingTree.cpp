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

int search(vector<int> arr, int start, int end, int key){
    for(int i=start; i<=end; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

Node* preOrderBuild(vector<int> preOrder, vector<int> inOrder, int start, int end){
    static int index = 0;
    if(start>end){
        return NULL;
    }
    int current = preOrder[index];
    index++;
    Node* n = new Node(current);
    if(start == end){
        return n;
    }

    int position = search(inOrder, start, end, current);
    n->left = preOrderBuild(preOrder, inOrder, start, position-1);
    n->right = preOrderBuild(preOrder, inOrder, position+1, end);
    return n;
}

void inOrderPrint(Node* root){
    if(root==NULL)
        return;
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

int main(){
    vector<int> preOrder{1,2,4,3,5};
    vector<int> inOrder{4,2,1,5,3};

    Node* root = preOrderBuild(preOrder, inOrder, 0, inOrder.size()-1);
    inOrderPrint(root);
}