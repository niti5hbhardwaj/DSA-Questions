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

class CircularLinkedList{
public:
    Node* head;

    CircularLinkedList(){
        head = NULL;
    }

    void insertAtHead(int val){
        Node* n = new Node(val);
        if(head==NULL){
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
    }

    void insertAtTail(int val){
        if(head==NULL){
            insertAtHead(val);
            return;
        }
        Node* n = new Node(val);
        Node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void display(){
        Node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        } while(temp!=head);
        cout<<endl;
    }

    void deleteAtHead(){
        Node* temp = head;
        Node* toDelete = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }


    void deleteNode(int val){
        if(head->data==val){
            deleteAtHead();
            return;
        }

        Node* temp = head;
        Node* toDelete = NULL;
        while(temp->next!=head){
            if(temp->next->data == val){
                toDelete = temp->next;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        delete toDelete;
    }
};

int main(){
    CircularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);
    cll.insertAtTail(4);
    cll.insertAtTail(5);

    cll.deleteNode(1);
    cll.display();
}