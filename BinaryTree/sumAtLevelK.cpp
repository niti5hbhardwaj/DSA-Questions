#include<iostream>
#include<queue>
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

void SumOfLevels(Node* root){
    if(root==NULL){
        return;
    }
    int sum = 0;
    int level = 1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current!=NULL){
            sum+=current->data;
            if(current->left!=NULL)
                q.push(current->left);
            if(current->right!=NULL)
                q.push(current->right);
        } else {
            cout<<"Sum of Level "<<level<<": "<<sum<<endl;
            sum = 0;
            level++;
            if(!q.empty())
                q.push(NULL);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    SumOfLevels(root);
}