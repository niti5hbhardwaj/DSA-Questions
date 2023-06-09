#include<iostream>
#include<stack>
using namespace std;

bool checkBalance(string str){
    stack<char> st;
    for(auto x: str){
        if(x=='(' || x=='{' || x=='['){
            st.push(x);
        } else {
            if(x==')' && st.top()=='('){
                st.pop();
            }
            if(x==']' &&  st.top()=='['){
                st.pop();
            }
            if(x=='}' && st.top()=='{'){
                st.pop();
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){
    string str = "({[()]})";
    cout<<checkBalance(str)<<endl;
}