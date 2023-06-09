#include<iostream>
#include<stack>
using namespace std;

int precedence(char c){
    if(c=='^'){
        return 3;
    } else if(c=='*' || c=='/'){
        return 2;
    } else if(c=='+' || c=='-'){
        return 1 ;
    } else {
        return -1;
    }
}

string infixToPostfix(string str){
    stack<char> st;
    string postfix = "";
    int i=0;
    while(str[i]!='\0'){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            postfix+= str[i];
        } else if(str[i]=='('){
            st.push(str[i]);
        } else if(str[i]==')'){
            while(!st.empty() && st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        } else {
            while(!st.empty() && precedence(str[i])<precedence(st.top())){
                postfix+=st.top();
                st.pop();
            }
            st.push(str[i]); 
        }
        i++;
    }

    while(!st.empty()){
        postfix+= st.top();
        st.pop(); 
    }
    return postfix;
}

int main(){
    string str = "(a-b/c)*(a/k-l)";
    string postfix = infixToPostfix(str);
    cout<<postfix<<endl;
}