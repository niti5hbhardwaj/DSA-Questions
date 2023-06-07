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

void insertAtTail(Node* &head, int data){
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

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtHead(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

bool search(Node* head, int val){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(Node* &head){
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteANode(Node* &head, int val){
    if(head == NULL){
        return;
    }
    if(head->data == val){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    Node* toDelete;
    while(temp!=NULL){
        if(temp->next->data == val){
            toDelete = temp->next;
            break;
        }
        temp = temp->next;
    }
    temp->next = temp->next->next;
    delete toDelete;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 1);
    deleteANode(head, 2);

    display(head);
    return 0;
}