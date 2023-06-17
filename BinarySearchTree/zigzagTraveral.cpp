#include<iostream>
#include<stack>
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
//https://youtu.be/xtuhK-a18is?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
void zigzagTraveral(Node* root){
    vector<int> traversal;
    if(root==NULL){
        return;
    }
    bool leftToRight = true;
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    currentLevel.push(root);
    while(!currentLevel.empty()){
        Node* currentNode = currentLevel.top();
        currentLevel.pop();
        traversal.push_back(currentNode->data);
        if(leftToRight){
            if(currentNode->left)
                nextLevel.push(currentNode->left);
            if(currentNode->right)
                nextLevel.push(currentNode->right);
        } else {
            if(currentNode->right)
                nextLevel.push(currentNode->right);
            if(currentNode->left)
                nextLevel.push(currentNode->left);
        }
        if(currentLevel.empty()){
            currentLevel.swap(nextLevel);
            leftToRight = !leftToRight;
        }
    }
    for(auto x: traversal){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    zigzagTraveral(root);

}