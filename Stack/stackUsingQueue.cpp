#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int val){
        q2.push(val);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
    }

    void pop(){
        if(q1.empty()){
            cout<<"Stack UndeFlow"<<endl;
            return;
        }
        q1.pop();
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack Empty"<<endl;
            return -1;
        }
        return q1.front();
    }
    
    bool isEmpty(){
        if(q1.empty()){
            return true;
        }
        return false; 
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;
}