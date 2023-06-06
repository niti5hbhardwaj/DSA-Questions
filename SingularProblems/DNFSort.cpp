#include<iostream>
using namespace std;

//https://youtu.be/2C4CQ32961Y?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
void DNFSort(vector<int> &arr, int size){
    int low = 0, high = size-1, mid = 0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            mid++; low++;
        } else if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
        } else{
            mid++;
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
    DNFSort(arr, size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}