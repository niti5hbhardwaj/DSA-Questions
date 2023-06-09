#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* back;
public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void push(int val){
        Node* n = new Node(val);
        if(front == NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue Empty"<<endl;
            return;
        }
        Node* toDelete = front;
        front = front->next;
        delete toDelete;
    }

    int peek(){
        if(front==NULL){
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front==NULL)
            return true;
        return false;
    }
};

int main(){
Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
}