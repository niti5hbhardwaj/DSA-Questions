#include<iostream>
#include<stack>
using namespace std;

//https://youtu.be/rlCSjCGc3Z0?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
bool redundantParenthesis(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            continue;
        } else if(str[i]==')'){
            if(st.top()=='('){
                return true;
            }
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
        } else {
            st.push(str[i]);
        }
    }
    if(st.empty())
        return false;
    return true;
}

int main(){
    string str = "(a+(a+b))";
    cout<<redundantParenthesis(str)<<endl;
}