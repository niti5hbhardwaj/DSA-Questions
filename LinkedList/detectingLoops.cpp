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

void makeCycle(Node* head, int pos){
    Node* loopingNode;
    Node* temp = head;
    int nodeNumber = 1;
    while(temp->next!=NULL){
        if(nodeNumber==pos)
            loopingNode = temp;
        temp = temp->next;
        nodeNumber++;
    }
    if(nodeNumber<pos){
        return;
    }
    temp->next = loopingNode;
}

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    fast = head;
    while(fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int main(){
    LinkedList ll;
    ll.insertAtTail(2);
    ll.insertAtTail(3); 
    ll.insertAtTail(4);
    ll.insertAtHead(1);
    Node* head = ll.getHead();
    makeCycle(head,3);
    removeCycle(head);
    return 0;
}