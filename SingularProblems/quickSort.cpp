#include<iostream>
using namespace std;

void swap(vector<int> &arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(vector<int> &arr, int l, int r){
    int pivot = arr[r];

    int position = l-1;
    for(int i=l;i<r;i++){
        if(arr[i]<=pivot){
            position++;
            swap(arr, position, i);
        }
    }
    swap(arr, position+1, r);
    return position+1;
}

void quickSort(vector<int> &arr, int l,  int r){
    if(l<r){
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,size-1);
    for(int i=0;i<size;i++){
       cout<<arr[i]<<" ";
    }
    return 0;
}