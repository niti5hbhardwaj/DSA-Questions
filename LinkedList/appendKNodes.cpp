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

    bool search(int val){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == val){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deleteAtHead(){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void deleteANode(int val){
        if(head == NULL){
            return;
        }
        if(head->data == val){
            deleteAtHead();
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

    void reverse(){
        if(head==NULL){
            return;
        }
        Node* prevNode = NULL;
        Node* currentNode = head;
        Node* nextNode = head->next;
        while(nextNode!=NULL){
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        currentNode->next = prevNode;
        head = currentNode;
        // return head;
    }

    Node* getHead(){
        return head;
    }

    void setHead(Node* newhead){
        head = newhead;
    }
};

int length(Node* head){
    int count=0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* appendKNode(Node* &head, int k){
    int l = length(head);
    Node* newHead = NULL;
    Node* newTail = NULL;
    Node* tail = NULL;
    Node* temp = head;
    int count = 1;
    while(temp!=NULL && count<=l){
        if(count==l-k)
            newTail = temp;
        if(count==l-k+1)
            newHead = temp;
        if(count==l)
            tail = temp;
        count++;
        temp = temp->next;
    }
    tail->next = head;
    newTail->next = NULL;
    return newHead;
}

int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    Node* head = ll.getHead();
    ll.setHead(appendKNode(head,3));
    ll.display();
}