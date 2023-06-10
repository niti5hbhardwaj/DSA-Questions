#include<iostream>
#include<stack>
using namespace std;

//https://youtu.be/XlD5VsOZsyA?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ

vector<int> stockSpan(vector<int> arr){
    vector<int> answer;
    stack<pair<int,int>> st;
    for(int i=0;i<arr.size();i++){
        int span = 1;
        while(!st.empty() && st.top().first<arr[i]){
            span+= st.top().second;
            st.pop();
        }
        st.push({arr[i], span});
        answer.push_back(span);
    }
    return answer;
}

int main(){
    vector<int> arr {100,80,60,70,60,75,85};
    vector<int> answer = stockSpan(arr);
    for(auto x: answer){
        cout<<x<<" ";
    }
}