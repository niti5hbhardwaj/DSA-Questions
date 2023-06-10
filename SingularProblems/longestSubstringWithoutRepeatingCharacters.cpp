#include<iostream>
using namespace std;

string longestSubstring(string str){
    vector<int> lastOccurence(26,-1);
    int start = -1, maxLength = INT_MIN;
    for(int i=0;i<str.size();i++){
        if(lastOccurence[str[i]-'a']!=-1){
            start = lastOccurence[str[i]-'a'];
        }
        lastOccurence[str[i]-'a'] = i;
        maxLength = max(maxLength, i-start);
    }
    return str.substr(start+1, maxLength);
}

int main(){
    string str = "pwwkerw";
    cout<<longestSubstring(str)<<endl;
}