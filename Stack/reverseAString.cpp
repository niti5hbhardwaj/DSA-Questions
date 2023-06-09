#include<iostream>
#include<stack>
using namespace std;

string reverseSentence(string str){
    stack<string> st;
    string word = "";
    int i=0;
    while(str[i]!='\0'){
        word+= str[i];
        if(str[i]==' '){
            st.push(word);
            word = "";
        }
        i++;
    }
    st.push(word+' ');
    string reverseStr = "";
    while(!st.empty()){
        reverseStr+= st.top();
        st.pop();
    } 
    return reverseStr;
}

int main(){
    string str = "Hello, how are you?";
    string reverseStr = reverseSentence(str);
    cout<<reverseStr<<endl;
}