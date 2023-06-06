#include<iostream>
#include<set>
using namespace std;

void firstRepeatingElementIndex(vector<int> array, int size){
    set<int> occurence;
    int index;
    for(int i=size-1;i>=0;i--){
        if(occurence.find(array[i])!=occurence.end()){
            index = i;
        } else{
            occurence.insert(array[i]);
        }
    }
    cout<<"First Repeating element at index "<<index;
}

int main(){
    int size;
    cin>>size;
    vector<int> array(size);
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    firstRepeatingElementIndex(array, size);
    return 0;
}