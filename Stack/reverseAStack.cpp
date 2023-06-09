#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int element = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, element);
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    stack<int> st;
    int arr[] = {1,2,3,4,5};
    for(int i=0;i<5;i++){
        st.push(arr[i]);
    }
    reverseStack(st);
    display(st);
}