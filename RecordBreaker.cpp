#include<iostream>
using namespace std;

vector<int> recordBreaker(int array[], int size){
    vector<int> recordBreakerDays;
    int maxTillNow = INT_MIN;
    for(int i=0;i<size-1;i++){
        if(array[i]>maxTillNow && array[i]>array[i+1]){
            recordBreakerDays.push_back(i);
            maxTillNow = max(maxTillNow, array[i]);
        }
    }
    if(array[size-1]>maxTillNow){
        recordBreakerDays.push_back(array[size-1]);
    }
    return recordBreakerDays;
}

int main(){
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    vector<int> recordBreakerDays = recordBreaker(array, size);
    for(auto x: recordBreakerDays){
        cout<<x<<" ";
    }
}