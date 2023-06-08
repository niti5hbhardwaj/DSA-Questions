#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    Node* head;
public:
    DoublyLinkedList(){
        head = NULL;
    }
    void insertAtTail(int val){
        Node* n = new Node(val);
        if(head==NULL){
            head = n;
            return;
        }
        
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }

    void insertAtHead(int val){
        Node* n = new Node(val);
        if(head==NULL){
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl; 
    }

    void deleteAtHead(){
        if(head==NULL){
            return;
        }
        Node* toDelete = head;
        head = head->next;
        head->prev = NULL;
        delete toDelete;
    }
    void deleteNode(int position){
        if(position == 1){
            deleteAtHead();
            return;
        }
        Node* temp = head;
        int count = 1;
        while(temp!=NULL && count!=position){
            temp = temp->next;
            count++;
        }
        temp->prev->next = temp->next;
        if(temp->next!=NULL){
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtHead(3);
    dll.insertAtHead(2);
    dll.insertAtHead(1);
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.insertAtTail(6);
    dll.display();
    dll.deleteNode(6);
    cout<<endl;
    dll.display();
}