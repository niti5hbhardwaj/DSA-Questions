#include<iostream>
using namespace std;

void towerOfHanoi(int noOfRings, char source, char destination, char helper){
    if(noOfRings==0){
        return;
    }

    towerOfHanoi(noOfRings-1, source, helper, destination);
    cout<<"Move from "<<source<<" to "<<destination<<endl;
    towerOfHanoi(noOfRings-1, helper, destination, source);
}

string removeDuplicates(string str){
    if(str.length()==0){
        return "";
    }
    string followingString = removeDuplicates(str.substr(1));
    if(str[0] == followingString[0])
        return followingString;
    return str[0] + followingString;
}

string moveXToLast(string str){
    if(str.length()==0){
        return "";
    }
    string followingString = moveXToLast(str.substr(1));
    if(str[0]=='X'){
        return (followingString+str[0]);
    }
    return (str[0]+followingString);
}

void substrings(string str, string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    substrings(str.substr(1), ans);
    substrings(str.substr(1), ans+str[0]);
}

string keypadArray[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string str, string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string possibleChars = keypadArray[ch-'0'];
    for(int i=0;i<possibleChars.length();i++){
        keypad(str.substr(1), ans+possibleChars[i]);
    }
}

void permutate(string str, string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        permutate(str.substr(0,i)+str.substr(i+1), ans+str[i]);
    }
}

int main(){
    string str = "ABC";
    permutate(str,"");
    return 0;
}