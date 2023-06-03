#include<iostream>
using namespace std;


bool PairSum(int array[], int size, int sum){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(array[i]+array[j]==sum){
                return true;
            }
        }
    }
    return false;
}

int PairSumUsingTwoPointer(int array[], int size, int sum){
    sort(array, array+size);
    int i=0, j=size-1;
    while(i<j){
        if(array[i]+array[j]==sum){
            return true;
        } else if(array[i]+array[j]>sum){
            j--;
        } else{
            i++;
        }
    }
    return false;
}

int main(){
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    int sum;
    cin>>sum;
    cout<<PairSumUsingTwoPointer(array,size,sum)<<endl;
    return 0;
}