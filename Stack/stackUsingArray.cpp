#include<iostream>
using namespace std;

#define n 100

class Stack{
    int* arr;
    int topOfStack;
public:
    Stack(){
        arr = new int[n];
        topOfStack = -1;
    }

    void push(int x){
        if(topOfStack==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        topOfStack++;
        arr[topOfStack] = x;
    }

    void pop(){
        if(topOfStack==-1){
            cout<<"Stack underflow"<<endl;;
            return;
        }
        topOfStack--;
    }

    int top(){
        if(topOfStack==-1){
            cout<<"Stack is empty"<<endl;
        }
        return arr[topOfStack];
    }

    bool isEmpty(){
        if(topOfStack==-1){
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