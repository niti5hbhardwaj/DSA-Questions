#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> s;
public:
    void push(int val){
        s.push(val);
    }

    int pop(){
        if(s.empty()){
            cout<<"Queue UnderFlow"<<endl;
            return -1;
        }
        int topValue = s.top();
        s.pop();
        if(s.empty()){
            return topValue;
        }
        int val = pop();
        s.push(topValue);
        return val;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(8);
    q.pop();
    q.push(9);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
}