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

int noOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftNodes = noOfNodes(root->left);
    int rightNodes = noOfNodes(root->right);
    return (leftNodes+rightNodes+1);
}

int sumOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return (root->data + leftSum + rightSum);
}

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int heightOfLeftSubtree = heightOfTree(root->left);
    int heightOfRightSubtree = heightOfTree(root->right);
    return (max(heightOfLeftSubtree, heightOfRightSubtree) + 1);
}

//https://youtu.be/9fj_-Sr84CU?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=205
int diameterOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int heightOfLeftSubtree = heightOfTree(root->left);
    int heightOfRightSubtree = heightOfTree(root->right);
    int currentDiameter =  heightOfLeftSubtree + heightOfRightSubtree + 1;

    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);
    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

//https://youtu.be/9fj_-Sr84CU?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=534
int optimisedDiameterOfTree(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int leftHeight = 0, rightHeight = 0;
    int leftDiameter = optimisedDiameterOfTree(root->left, &leftHeight);
    int rightDiameter = optimisedDiameterOfTree(root->right, &rightHeight);

    int currentDiameter = leftHeight + rightHeight + 1;
    *height = max(leftHeight, rightHeight) +1;
    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

int main(){
    Node* root = new Node(1);
    root->left =  new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<optimisedDiameterOfTree(root, &height)<<endl;
}