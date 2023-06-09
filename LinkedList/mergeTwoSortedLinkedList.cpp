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

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int data){
        Node* n = new Node(data);
        if(head==NULL){
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void insertAtHead(int data){
        Node* n = new Node(data);
        n->next = head;
        head = n;
    }

    Node* getHead(){
        return head;
    }

    void setHead(Node* newhead){
        head = newhead;
    }
};

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* mergeSortedLists(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(0);
    Node* temp3 = dummyNode;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp3->next = temp1;
            temp1 = temp1->next;
        } else{
            temp3->next = temp2;
            temp2 = temp2->next;
        }
            temp3 = temp3->next;

    }

    while(temp1!=NULL){
        temp3->next = temp1;
        temp3 = temp3->next;
        temp1 = temp1->next;
    }

    while(temp2!=NULL){
        temp3->next = temp2;
        temp3 = temp3->next;
        temp2 = temp2->next;
    }

    return dummyNode->next;
}

Node* mergeRecursive(Node* head1, Node* head2){
    if(head1==NULL){
        return head1;
    }
    if(head2==NULL){
        return head2;
    }

    Node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}

int main(){
    LinkedList ll1;
    LinkedList ll2;

    ll1.insertAtTail(1);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(8);
    ll1.insertAtTail(10);

    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(5);
    ll2.insertAtTail(7);
    ll2.insertAtTail(8);

    Node* head1 = ll1.getHead();
    Node* head2 = ll2.getHead();
    Node* head3 = mergeRecursive(head1, head2);
    display(head3);
    
}