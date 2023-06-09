#include<iostream>
#include<stack>
using namespace std;

int evaluate(int firstNumber, int secondNumber, char symbol){
    if(symbol=='+'){
        return firstNumber+secondNumber;
    } else if(symbol=='-'){
        return firstNumber-secondNumber;
    } else if(symbol=='*'){
        return firstNumber*secondNumber;
    } else if(symbol=='/'){
        return firstNumber/secondNumber;
    } else {
        return firstNumber%secondNumber;
    }
    return 0;
}

int prefix(string exp){
    if(exp.length()==0){
        return 0;
    }
    stack<int> st;
    int i = exp.length()-1;
    while(i>=0){
        if(exp[i]>='0' && exp[i]<='9')
            st.push(exp[i]-'0');
        else{
            int firstNumber = st.top(); st.pop();
            int secondNumber = st.top(); st.pop();
            int ans = evaluate(firstNumber, secondNumber, exp[i]);
            st.push(ans);
        }
        i--;
    }
    return st.top();
}

int postfix(string exp){
    if(exp.length()==0){
        return 0;
    }
    stack<int> st;
    int i = 0;
    while(i<exp.length()){
        if(exp[i]>='0' && exp[i]<='9'){
            st.push(exp[i]-'0');
        } else {
            int secondNumber = st.top(); st.pop();
            int firstNumber  = st.top(); st.pop();
            int ans = evaluate(firstNumber, secondNumber, exp[i]);
            st.push(ans);
        }
        i++;
    }
    return st.top();
}

int main(){
    string exp = "46+2/5*7+";
    int result = postfix(exp);
    cout<<result<<endl;
}