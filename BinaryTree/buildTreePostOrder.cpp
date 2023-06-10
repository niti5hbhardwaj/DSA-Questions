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

int search(vector<int> inOrder, int start, int end, int key){
    for(int i=start;i<=end;i++){
        if(inOrder[i]==key)
            return i;
    }
    return -1;
}

Node* postOrderBuild(vector<int> postOrder, vector<int> inOrder, int start, int end){
    static int index = postOrder.size()-1;
    if(start>end){
        return NULL;
    }
    int current = postOrder[index];
    index--;
    Node* n = new Node(current);
    if(start==end){
        return n;
    }
    int position = search(inOrder, start, end, current);
    n->right = postOrderBuild(postOrder, inOrder, position+1, end);
    n->left = postOrderBuild(postOrder, inOrder, start, position-1);
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
    vector<int> postOrder{4,2,5,3,1};
    vector<int> inOrder{4,2,1,5,3};

    Node* root = postOrderBuild(postOrder, inOrder, 0, inOrder.size()-1);
    inOrderPrint(root);

}