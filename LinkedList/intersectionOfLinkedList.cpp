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
    Node* temp = head;
    int l = 0;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

void intersect(Node* head1, Node* head2, int pos){
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(--pos){
        temp1 = temp1->next;
    }

    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersectionPoint(Node* head1, Node* head2){
    int length1 = length(head1);
    int length2 = length(head2);

    int difference = 0;
    Node* longerList;
    Node* shorterList;
    if(length1>length2){
        difference = length1-length2;
        longerList = head1;
        shorterList = head2;
    } else {
        difference = length2 - length1;
        longerList = head2;
        shorterList = head1;
    }

    while(difference){
        longerList = longerList->next;
        difference--;
    }
    
    while(longerList!=NULL &&shorterList!=NULL){
        if(longerList==shorterList){
            return longerList->data;
        }
        longerList = longerList->next;
        shorterList = shorterList->next;
    }
    return -1;
}

int main(){
    LinkedList ll1;
    LinkedList ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    ll2.insertAtTail(1);
    ll2.insertAtTail(2);

    Node* head1 = ll1.getHead();
    Node* head2 = ll2.getHead();

    intersect(head1, head2, 4);

    cout<<intersectionPoint(head1, head2)<<endl;
}