#include<iostream>
using namespace std;

int maxLengthArithmeticSubarray(int arr[], int size){
    int commonDifference = arr[0] - arr[1];
    int maxLength = 0;
    int currentLength = 1;
    for(int i=0;i<size-1;i++){
        if(arr[i]-arr[i+1]==commonDifference){
            currentLength++;
        } else{
            commonDifference = arr[i] - arr[i+1];
            currentLength = 2;
        }
        if(currentLength>maxLength){
            maxLength = currentLength;
        }
    }
    return maxLength;
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<maxLengthArithmeticSubarray(arr, size)<<endl;
}