#include<iostream>
using namespace std;

void countSort(vector<int> &arr, int size){
    int maxElement = INT_MIN;
    for(auto x: arr){
        if(maxElement<x){
            maxElement = x;
        }
    }

    vector<int> frequency(maxElement+1, 0);
    for(auto x: arr){
        frequency[x]++;
    }

    int cumulativeSum = 0;
    for(int i=0; i<frequency.size(); i++){
        frequency[i]+= cumulativeSum;
        cumulativeSum = frequency[i];
    }

    vector<int> output(size);
    int position = -1;
    for(int i=0;i<size;i++){
        position = --frequency[arr[i]];
        output[position] = arr[i];
    }

    arr.swap(output);

}

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    countSort(arr, size);
    for(auto x: arr){
        cout<<x<<" ";
    }
}