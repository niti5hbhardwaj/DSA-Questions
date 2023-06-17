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

bool identical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1!=NULL && root2!=NULL){
        if(root1->data==root2->data){
            bool leftIdentical = identical(root1->left, root2->left);
            bool rightIdentical = identical(root1->right, root2->right);
            return leftIdentical && rightIdentical;
        }
    }
    return false;
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(4);
    root1->right->right = new Node(5);
    root1->left->right->left = new Node(6);
    root1->left->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->right = new Node(4);
    root2->right->right = new Node(5);
    root2->left->right->left = new Node(6);
    root2->left->right->right = new Node(8);

    cout<<identical(root1, root2)<<endl;
}