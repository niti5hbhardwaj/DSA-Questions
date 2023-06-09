#include<iostream>
using namespace std;

#define n 100

class Queue{
    int front;
    int back;
    int* arr;
public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int val){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=val;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
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