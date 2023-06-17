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

//https://youtu.be/1ZAotQGnbi4?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
vector<Node*> constructBST(int start,  int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        vector<Node*> leftSubtrees = constructBST(start, i-1);
        vector<Node*> rightSubtrees = constructBST(i+1, end);

        for(int j=0;j<leftSubtrees.size();j++){
            Node* left = leftSubtrees[j]; 
            for(int k=0;k<rightSubtrees.size();k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }

    return trees;
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int n = 3;
    vector<Node*> trees = constructBST(1,n);
    for(auto root: trees){
        preOrder(root);
        cout<<endl<<endl;
    }
}