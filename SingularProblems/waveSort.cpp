#include<iostream>
using namespace std;

//https://youtu.be/N97M67GQTwI?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
void waveSort(vector<int> &arr, int size){
    for(int i=1;i<size;i=i+2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1] && i<=size-2){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    waveSort(arr,size);
    for(auto x: arr){
        cout<<x<<" ";
    }
}